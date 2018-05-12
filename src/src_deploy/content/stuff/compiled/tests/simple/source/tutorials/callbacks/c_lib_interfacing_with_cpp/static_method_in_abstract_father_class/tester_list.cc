#include <iostream> 
#include <list>

#include <stdio.h>

#include "callbacks/children.hh"
#include "lib/c_library.h"

int main(void)
{
  using namespace std;

  MyContainer container;
  list<CallbacksFather *> vec;
  
  vec.push_back( new MyWeightedSquarer() );
  vec.push_back( new MyWeightedSquareRooter(2.5) );
  
  container.callback = &CallbacksFather::s_callback;
  
  double number = 5.0;
  unsigned int ii = -1;
  for ( list<CallbacksFather *>::iterator it=vec.begin() ; it != vec.end() ; ++it )
  {
    ii++;
    
    container.userdata = (void *) *it;
    
    double result = caller( &container , number );
    
    cout << "Instance of Class : \"" << (*it)->classname() << "\"" << endl;
//     cout << "Result : " << result << endl;
    printf( "Result : %16.6f\n" , result );
    
    if ( ii < -1 + vec.size() )
    {
      cout << endl;
    }
  }
  
  // deleting
  for ( list<CallbacksFather *>::iterator it=vec.begin() ; it != vec.end() ; ++it )
  {
    delete *it;
  }
  
  return 0;
}
