/*
 * This file is part of the "dev-in-place" repository located at:
 * https://github.com/osuvak/dev-in-place
 * 
 * Copyright (C) 2018  Onder Suvak
 * 
 * For licensing information check the above url.
 * Please do not remove this header.
 * */

#include <itpp/itbase.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <iomanip>

#include <cmath>
#include <cstdio>

#include <omp.h>

#include "prng_static_ctor.hh"

#define USE_OPENMP
#define USE_TRANSFORM_FOR_POWERING

void
compute_pi_approx
(
        std::vector<double> &       vec_pi_approx ,
  const std::vector<unsigned int> & noMC
);

int
main (void)
{
  using namespace itpp;
  
  double limitL = 2.0 , limitH = 7.0;
  int    noExpo = 8;
  
  vec v_expo = linspace( limitL , limitH , noExpo );
  
#ifndef USE_TRANSFORM_FOR_POWERING
  std::vector<unsigned int> noMC;
  noMC.reserve( noExpo );
  
  std::for_each
    ( 
      v_expo._data() , 
      v_expo._data() + noExpo ,
      [&](const double &expo) 
        { noMC.push_back( static_cast<unsigned int>( pow( 10.0 , expo ) ) ); }
    );
#else
  std::vector<unsigned int> noMC( noExpo , 0.0 );
  
  std::transform
    ( 
      v_expo._data() , 
      v_expo._data() + noExpo ,
      noMC.begin() , 
      [](const double expo) 
        { return static_cast<unsigned int>( pow( 10.0 , expo ) ); }
    );
#endif
    
  std::vector<double> vec_pi_approx;
  vec_pi_approx.reserve( noMC.size() );
  
  tic();
  compute_pi_approx( vec_pi_approx , noMC );
  
  char tmp[256];
  std::cout 
    << std::setw(16) << "No. of Trials" << std::string( 4 , ' ' ) 
    << "PI Approximation" << std::endl;
  std::cout << std::endl;
  for( unsigned int ii = 0 ; ii < vec_pi_approx.size() ; ++ii )
  {
    sprintf( tmp , "%14.10f" , vec_pi_approx[ii] );
    std::cout 
      << std::setw(16) << noMC[ii] << std::string( 4 , ' ' )
      << tmp << std::endl;
  }
  std::cout << std::endl;
  toc_print();
  
  return 0;
}

void
compute_pi_approx
(
        std::vector<double> &       vec_pi_approx ,
  const std::vector<unsigned int> & noMC
)
{
  using namespace os_prng_sc;
  using namespace itpp;
  
  auto   center = std::make_pair( (double) 0.5 , (double) 0.5 );
  double radius = 0.5;
  
  vec v_trialsMC( *(noMC.rbegin()) );
  
  auto fh = 
      [&]( double & number )
        { 
          double distance_from_center 
            = sqrt( 
                    pow( PRNG_Static::rand(1)[0] - center.first  , 2.0 ) 
                  + pow( PRNG_Static::rand(1)[0] - center.second , 2.0 ) 
                  );
          if ( distance_from_center < radius )
            number = 1.0;
          else
            number = 0.0;
        };
        
//   tic();
#ifndef USE_OPENMP
  std::for_each
    ( 
      v_trialsMC._data() ,
      v_trialsMC._data() + v_trialsMC.size() ,
      fh
    );
#else
  #pragma omp parallel
  {
    #pragma omp for schedule(static) nowait
    for( unsigned int ii = 0 ; ii < v_trialsMC.size() ; ++ii )
      fh( v_trialsMC[ii] );
  }
#endif
//   toc_print();
//   std::cout << std::endl;
  
  v_trialsMC = cumsum( v_trialsMC );
  std::for_each
    (
      noMC.begin() ,
      noMC.end() ,
      [&] ( const unsigned int myIndex )
        { vec_pi_approx.push_back( 4.0 * v_trialsMC[ myIndex - 1 ] / myIndex ); }
    );
}