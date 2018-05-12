#ifndef CALLBACKS_CHILDREN_HH_
#define CALLBACKS_CHILDREN_HH_

#include "callbacks/father.hh"

#include <cmath>
#include <string>

class MyWeightedSquarer : public CallbacksFather
{
private:
  double coef_;
  static const std::string classname_;
  
public:
  MyWeightedSquarer 
  ( double coef = 2.0 ) 
  : 
  CallbacksFather(classname_) ,
  coef_(coef)
  {}
  
  virtual ~MyWeightedSquarer() {}
  
  virtual
  double
  callback
  ( double number ) 
  {
    return pow( number , 2 ) * this->coef_;
  }
};

class MyWeightedSquareRooter : public CallbacksFather
{
private:
  double coef_;
  static const std::string classname_;

public:
  MyWeightedSquareRooter 
  ( double coef = 3.0 ) 
  : 
  CallbacksFather(classname_) ,
  coef_(coef)
  {}
  
  virtual ~MyWeightedSquareRooter() {}
  
  virtual
  double
  callback
  ( double number ) 
  {
    return sqrt( number * this->coef_ );
  }
};

#endif