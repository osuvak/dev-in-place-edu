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
