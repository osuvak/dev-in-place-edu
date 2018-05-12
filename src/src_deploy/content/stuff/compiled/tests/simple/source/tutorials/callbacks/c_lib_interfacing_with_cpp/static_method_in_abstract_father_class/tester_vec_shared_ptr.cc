#include <iostream> 
#include <vector>
#include <memory>

#include <stdio.h>

#include "callbacks/children.hh"
#include "lib/c_library.h"

int main(void)
{
  using namespace std;

  MyContainer container;
  vector< shared_ptr< CallbacksFather > > vec;
  
//   vec.emplace_back( std::move( std::make_shared<MyWeightedSquarer>() ) );
//   vec.emplace_back( std::move( std::make_shared<MyWeightedSquareRooter>(2.5) ) );
  
  vec.emplace_back( std::make_shared<MyWeightedSquarer>() );
  vec.emplace_back( std::make_shared<MyWeightedSquareRooter>(2.5) );
  
  container.callback = &CallbacksFather::s_callback;
  
  double number = 5.0;
  
  for ( unsigned int ii = 0 ; ii < vec.size() ; ii++ )
  {
    container.userdata = (void *) vec[ii].get();
    
    double result = caller( &container , number );
    
    cout << "Instance of Class : \"" << vec[ii]->classname() << "\"" << endl;
//     cout << "Result : " << result << endl;
    printf( "Result : %16.6f\n" , result );
    
    if ( ii < -1 + vec.size() )
    {
      cout << endl;
    }
  }

  return 0;
}
