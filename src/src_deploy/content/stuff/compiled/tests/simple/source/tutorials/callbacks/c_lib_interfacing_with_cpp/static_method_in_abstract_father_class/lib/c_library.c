/*
 * This file is part of the "dev-in-place" repository located at:
 * https://github.com/osuvak/dev-in-place
 * 
 * Copyright (C) 2018  Onder Suvak
 * 
 * For licensing information check the above url.
 * Please do not remove this header.
 * */

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