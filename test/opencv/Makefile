TARGET=opencl-opencv-test
TEST_ORIGINAL=yes
TEST_CORE=yes
TEST_IMGPROC=yes
TEST_STITCHING=yes
TEST_PHOTO=yes
TEST_VIDEO=yes
TEST_FEATURE2D=yes
RPI3=no

all: $(TARGET)

VPATH=./modules/imgproc/test/ocl \
	./modules/ts/src \
	./modules/core/test/ocl \
	./modules/stitching/test/ocl \
	./modules/core/test/ocl \
	./modules/photo/test/ocl \
	./modules/video/test/ocl \
	./modules/features2d/test/ocl

CXX=g++

CXXFLAGS=-g \
	-D__OPENCV_BUILD \
	-std=gnu++11 \
	-O0 \
	-I/usr/include/eigen3 \
	-I/usr/local/include/opencv2  \
	-I. \
	-I./modules \
	-I./modules/ts/include \
	-I./modules/core/include \
	-I./modules/imgproc/test \
	-I./modules/imgproc/src

ifeq ($(RPI3), yes)
CXXFLAGS+=-mtune=cortex-a53 \
	-march=armv8-a+crc \
	-mcpu=cortex-a53 \
	-mfpu=crypto-neon-fp-armv8
else
CXXFLAGS+=-march=armv7-a \
	-mfpu=neon-vfpv4 \
	-mfloat-abi=hard 
endif

LDFLAGS=-lopencv_core \
	-lopencv_imgproc \
	-lopencv_video \
	-lopencv_imgcodecs \
	-lopencv_videoio \
	-lopencv_highgui \
	-lopencv_stitching \
	-lopencv_photo \
	-lopencv_features2d \
	-lOpenCL \
	-lgtest \
	-lpthread \
	-lstdc++ \
	-lm \
	-Lgtest

# modules/ts/src
OBJS=ocl_test.o \
	ocl_perf.o \
	ts_gtest.o \
	ts_perf.o \
	ts_func.o \
	ts.o

# original test cases
ifeq ($(TEST_ORIGINAL), yes)
OBJS+=opencl-opencv-test.o
endif

ifeq ($(TEST_IMGPROC), yes)
# modules/imgproc/test/ocl
OBJS+=test_imgproc.o \
	test_accumulate.o \
	test_blend.o \
	test_boxfilter.o \
	test_canny.o \
	test_color.o \
	test_filter2d.o \
	test_filters.o \
	test_gftt.o \
	test_histogram.o \
	test_houghlines.o \
	test_match_template.o \
	test_medianfilter.o \
	test_pyramids.o \
	test_sepfilter2d.o \
	test_warp.o 
endif

ifeq ($(TEST_STITCHING), yes)
# modules/stitching/test/ocl
OBJS+=test_warpers.o
endif

ifeq ($(TEST_CORE), yes)
# modules/core/test/ocl
OBJS+=test_dft.o \
	test_channels.o \
	test_image2d.o \
	test_matrix_operation.o \
	test_gemm.o \
	test_opencl.o \
	test_matrix_expr.o \
	test_arithm.o
endif

ifeq ($(TEST_PHOTO), yes)
# modules/photo/test/ocl
OBJS+=test_denoising.o
endif

ifeq ($(TEST_VIDEO), yes)
# modules/video/test/ocl
OBJS+=test_optflow_tvl1flow.o \
	test_optflow_farneback.o \
	test_bgfg_mog2.o \
	test_optflowpyrlk.o
endif

ifeq ($(TEST_FEATURE2D), yes)
# modules/features2d/test/ocl
OBJS+=test_feature2d.o \
	test_brute_force_matcher.o
endif

$(TARGET): $(OBJS)

clean:
	rm -f $(TARGET) $(OBJS) *~

