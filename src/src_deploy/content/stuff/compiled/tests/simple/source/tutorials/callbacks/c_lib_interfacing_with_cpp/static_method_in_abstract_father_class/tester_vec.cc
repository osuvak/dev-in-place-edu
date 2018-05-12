#include <iostream> 
#include <vector>

#include <stdio.h>

#include "callbacks/children.hh"
#include "lib/c_library.h"

int main(void)
{
  using namespace std;

  MyContainer container;
  vector<CallbacksFather *> vec;
  
  vec.push_back( new MyWeightedSquarer() );
  vec.push_back( new MyWeightedSquareRooter(2.5) );
  
  container.callback = &CallbacksFather::s_callback;
  
  double number = 5.0;
  
  for ( unsigned int ii = 0 ; ii < vec.size() ; ii++ )
  {
    container.userdata = (void *) vec[ii];
    
    double result = caller( &container , number );
    
    cout << "Instance of Class : \"" << vec[ii]->classname() << "\"" << endl;
//     cout << "Result : " << result << endl;
    printf( "Result : %16.6f\n" , result );
    
    if ( ii < -1 + vec.size() )
    {
      cout << endl;
    }
  }
  
  // deleting
  for ( unsigned int ii = 0 ; ii < vec.size() ; ii++ )
  {
    delete vec[ii];
  }
  
  return 0;
}
