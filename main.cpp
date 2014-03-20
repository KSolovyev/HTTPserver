
#include "looper.h"

#define DEFAULT_PORT 9876



int main( int argc, char **argv )
{
  int port = DEFAULT_PORT;

  if( argc > 1 )  port = atoi( argv[1] );
  if( port < 0 || port > 65535 )
  {
    fprintf( stderr, "Задан некорректный номер порта.\n" );
    return -1;
  }
  const Looper* looper = Looper::Instance(port);
  looper->run();
}
