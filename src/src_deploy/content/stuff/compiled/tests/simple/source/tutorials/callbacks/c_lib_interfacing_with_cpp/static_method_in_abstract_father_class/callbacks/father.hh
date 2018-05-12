#ifndef CALLBACKS_FATHER_HH_
#define CALLBACKS_FATHER_HH_

#include <string>

class CallbacksFather
{
protected:
  std::string classname_dyn_;
  
public:
  CallbacksFather
  ( std::string arg_classname = "" ) 
  :
  classname_dyn_(arg_classname)
  {}
  
  virtual ~CallbacksFather() {}
  
  static
  double
  s_callback
  (
    double  number ,
    void   *userdata
  )
  {
    CallbacksFather *current = (CallbacksFather *) userdata;
    return current->callback(number);
  }
  
  std::string
  classname
  ()
  { return this->classname_dyn_; }
  
  virtual
  double
  callback
  ( double number ) 
  = 0;
};

#endif
