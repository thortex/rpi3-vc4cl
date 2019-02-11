#!/bin/sh -x

(make \
     TEST_ORIGINAL=yes \
     TEST_CORE=no  \
     TEST_IMGPROC=no \
     TEST_STITCHING=no \
     TEST_PHOTO=no \
     TEST_VIDEO=no \
     TEST_FEATURE2D=no \
     RPI3=yes)

#LD_LIBRARY_PATH=gtest ./opencl-opencv-test --gtest_filter=OCL_Arithm/Add.Mat/$1
