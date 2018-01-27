TMP_DIR         := $(HOME)/sw_temp/opencv_3.2.0_20170302_1500/opencv-3.2.0_install
TMP_DIR_INCLUDE := $(TMP_DIR)/include
TMP_DIR_LIB     := $(TMP_DIR)/lib

TMP_LIB :=  \
		-lopencv_calib3d \
		-lopencv_core \
		-lopencv_features2d \
		-lopencv_flann \
		-lopencv_highgui \
		-lopencv_imgcodecs \
		-lopencv_imgproc \
		-lopencv_ml \
		-lopencv_objdetect \
		-lopencv_photo \
		-lopencv_shape \
		-lopencv_stitching \
		-lopencv_superres \
		-lopencv_videoio \
		-lopencv_video \
		-lopencv_videostab
		
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
