# /*
#  * This file is part of the "dev-in-place" repository located at:
#  * https://github.com/osuvak/dev-in-place
#  * 
#  * Copyright (C) 2017  Onder Suvak
#  * 
#  * For licensing information check the above url.
#  * Please do not remove this header.
#  * */

TMP_DIR         := $(HOME)/sw_temp/opencv_3.2.0_20170302_1500/opencv-3.2.0_install
TMP_DIR_INCLUDE := $(TMP_DIR)/include
TMP_DIR_LIB     := $(TMP_DIR)/lib

TMP_LIB :=  \
	libopencv_calib3d.so \
	libopencv_core.so \
	libopencv_features2d.so \
	libopencv_flann.so \
	libopencv_highgui.so \
	libopencv_imgcodecs.so \
	libopencv_imgproc.so \
	libopencv_ml.so \
	libopencv_objdetect.so \
	libopencv_photo.so \
	libopencv_shape.so \
	libopencv_stitching.so \
	libopencv_superres.so \
	libopencv_videoio.so \
	libopencv_video.so \
	libopencv_videostab.so

TMP_LIB := $(TMP_LIB:lib%.so=-l%)

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