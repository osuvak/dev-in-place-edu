TMP_DIR_LIB     := $(HOME)/sw_temp/acml_04_04_00_b32/gfortran32/lib

TMP_LIB :=  \
	-lacml

# compile and link dependencies
DEP_LINK_TMP := \
	-L$(TMP_DIR_LIB) $(TMP_LIB)
	
PATH_LINK_TMP := \
	$(TMP_DIR_LIB)

# append

# DEP_INCLUDE     +=
# DEP_INCLUDE_RAW +=
DEP_LINK        += $(DEP_LINK_TMP)

PATH_LINK:=$(PATH_LINK):$(PATH_LINK_TMP)

# undefine TMP_DIR
# undefine TMP_DIR_INCLUDE
undefine TMP_DIR_LIB
undefine TMP_LIB
undefine DEP_LINK_TMP
undefine PATH_LINK_TMP
# undefine DEP_INCLUDE_TMP
