TMP_DIR         := $(HOME)/sw_temp/fftw_03.03.04_20170302_1541/fftw-3.3.4_install
TMP_DIR_INCLUDE := $(TMP_DIR)/include
TMP_DIR_LIB     := $(TMP_DIR)/lib
 
TMP_LIB :=  \
	-lfftw3

DEP_LINK_TMP := \
	-L$(TMP_DIR_LIB) $(TMP_LIB)
	
PATH_LINK_TMP := \
	$(TMP_DIR_LIB)
	
DEP_INCLUDE_TMP := \
	-I$(TMP_DIR_INCLUDE)
	
# append

DEP_INCLUDE     += $(DEP_INCLUDE_TMP)
DEP_INCLUDE_RAW += $(TMP_DIR_INCLUDE)
DEP_LINK        += $(DEP_LINK_TMP)

PATH_LINK:=$(PATH_LINK):$(PATH_LINK_TMP)

undefine TMP_DIR
undefine TMP_DIR_INCLUDE
undefine TMP_DIR_LIB
undefine TMP_LIB
undefine DEP_LINK_TMP
undefine PATH_LINK_TMP
undefine DEP_INCLUDE_TMP
