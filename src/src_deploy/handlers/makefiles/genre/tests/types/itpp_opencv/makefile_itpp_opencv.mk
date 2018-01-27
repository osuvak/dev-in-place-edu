# /*
#  * This file is part of the "dev-in-place" repository located at:
#  * https://github.com/osuvak/dev-in-place
#  * 
#  * Copyright (C) 2017  Onder Suvak
#  * 
#  * For licensing information check the above url.
#  * Please do not remove this header.
#  * */

DEP_INCLUDE:=
DEP_INCLUDE_RAW:=
DEP_LINK:=
PATH_LINK:=

include $(HOME)/dev_in_place/lib_info/config_lib_itpp_04.03.01_20170302_1603.mk
include $(HOME)/dev_in_place/lib_info/config_lib_opencv_3.2.0_20170302_1500.mk
include $(HOME)/dev_in_place/lib_info/config_lib_fftw_03.03.04_20170302_1541.mk
include $(HOME)/dev_in_place/lib_info/config_lib_acml_04_04_00_gfortran_32bit.mk
# include $(HOME)/dev_in_place/lib_info/.mk
include $(HOME)/dev_in_place/lib_info/config_system_lib.mk

include $(HOME)/dev_in_place/makefiles/genre/tests/makefile_in_place_tests.mk 