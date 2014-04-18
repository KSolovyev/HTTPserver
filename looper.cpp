#include "looper.h"


Looper* Looper::looper;
Tasker* Looper::tasker = new Tasker;

Looper *Looper::getInstance()
{
//    if(!looper){
//        looper = new Looper;
//    }
    return Looper::looper;
}

void Looper::init(int port)
{
    if(!Looper::looper)
            Looper::looper = new Looper(port);

}


void Looper::run() const
{
    event_base_dispatch( base );
}

Looper::Looper(int port)
{
base = event_base_new();
  if( !base )
  {
    fprintf( stderr, "Ошибка при создании объекта event_base.\n" );
//    return -1;
  }

  struct sockaddr_in sin;
  memset( &sin, 0, sizeof(sin) );
  sin.sin_family = AF_INET;    /* работа с доменом IP-адресов */
  sin.sin_addr.s_addr = htonl( INADDR_ANY );  /* принимать запросы с любых адресов */
  sin.sin_port = htons( port );

  listener = evconnlistener_new_bind( base, accept_connection_cb, NULL,
                                     (LEV_OPT_CLOSE_ON_FREE | LEV_OPT_REUSEABLE),
                                     -1, (struct sockaddr *)&sin, sizeof(sin) );
  if( !listener )
  {
    perror( "Ошибка при создании объекта evconnlistener" );
//    return -1;
  }
  evconnlistener_set_error_cb( listener, accept_error_cb);




}


void Looper::accept_error_cb( struct evconnlistener *listener, void *arg )
{
  struct event_base *base = evconnlistener_get_base( listener );
  int error = EVUTIL_SOCKET_ERROR();
  fprintf( stderr, "Ошибка %d (%s) в мониторе соединений. Завершение работы.\n",
           error, evutil_socket_error_to_string( error ) );
  event_base_loopexit( base, NULL );
}

void Looper::accept_connection_cb( struct evconnlistener *listener,
                   evutil_socket_t fd, struct sockaddr *addr, int sock_len,
                   void *arg )
{
  /* При обработке запроса нового соединения необходимо создать для него
     объект bufferevent */
  struct event_base *base = evconnlistener_get_base( listener );
  struct bufferevent *buf_ev = bufferevent_socket_new( base, fd, BEV_OPT_CLOSE_ON_FREE );

  bufferevent_setcb( buf_ev, echo_read_cb, NULL, echo_event_cb, NULL );
  bufferevent_enable( buf_ev, (EV_READ | EV_WRITE) );
}

void Looper::echo_read_cb( struct bufferevent *buf_ev, void *arg )
{
  //struct evbuffer *buf_input = bufferevent_get_input( buf_ev );
  //struct evbuffer *buf_output = bufferevent_get_output( buf_ev );

  /* Данные просто копируются из буфера ввода в буфер вывода */
  //evbuffer_add_buffer( buf_output, buf_input );

  tasker->pushTask(new SimpleTask(buf_ev));
}

void Looper::echo_event_cb( struct bufferevent *buf_ev, short events, void *arg )
{
  if( events & BEV_EVENT_ERROR )
    perror( "Ошибка объекта bufferevent" );
  if( events & (BEV_EVENT_EOF | BEV_EVENT_ERROR) )
    bufferevent_free( buf_ev );
}
