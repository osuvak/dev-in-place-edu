/*
 * This file is part of the "dev-in-place" repository located at:
 * https://github.com/osuvak/dev-in-place
 * 
 * Copyright (C) 2018  Onder Suvak
 * 
 * For licensing information check the above url.
 * Please do not remove this header.
 * */

#ifndef C_LIBRARY_H_
#define C_LIBRARY_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct MyContainer_
{
  double (*callback)( double , void* );
  void *userdata;
}MyContainer;

double
caller
(
  MyContainer *container ,
  double       number
);

#ifdef __cplusplus
}
#endif

#endif
