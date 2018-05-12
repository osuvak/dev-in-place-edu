#include "lib/c_library.h" 

double
caller
(
  MyContainer *container ,
  double       number
)
{
  return container->callback( number , container->userdata );
}