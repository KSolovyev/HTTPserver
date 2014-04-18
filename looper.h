#ifndef LOOPER_H
#define LOOPER_H
#include <event2/util.h>
#include "allForLibevent.h"


class Tasker;
//extern struct evbuffer *bufferevent_get_input(struct bufferevent *bufev);

class Looper
{
public:
    static Looper* getInstance();
    static void init(int port);

   // static const Looper* Instance(int port);
    void run() const;

private:
    static Looper* looper;
    Looper(int port);
    static Tasker* tasker;
    static void accept_error_cb( struct evconnlistener *listener, void *arg );
    static void accept_connection_cb( struct evconnlistener *listener,
                   evutil_socket_t fd, struct sockaddr *addr, int sock_len,
                   void *arg );
    static void echo_read_cb( struct bufferevent *buf_ev, void *arg );
    static void echo_write_cb( struct bufferevent *buf_ev, void *arg );
    static void echo_event_cb( struct bufferevent *buf_ev, short events, void *arg );

    struct event_base *base;
    struct evconnlistener *listener;


};

#endif // LOOPER_H
