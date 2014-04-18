#include "allForLibevent.h"

#define DEFAULT_PORT 80



int main( int argc, char **argv )
{
  int port = DEFAULT_PORT;

  if( argc > 1 )  port = atoi( argv[1] );
  if( port < 0 || port > 65535 )
  {
    fprintf( stderr, "Задан некорректный номер порта.\n" );
    return -1;
  }
  Looper::init(port);
  Looper::getInstance()->run();
  //ParsedRequest* pr = new ParsedRequest_impl;
}
