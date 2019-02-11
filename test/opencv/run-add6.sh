#!/bin/sh -x
# OK
sudo sh -c "(LD_LIBRARY_PATH=/usr/local/lib ./opencl-opencv-test --gtest_filter='OCL_Arithm/Add.Mat/9')"
sudo sh -c "(LD_LIBRARY_PATH=/usr/local/lib ./opencl-opencv-test --gtest_filter='OCL_Arithm/Add.Mat/24')"
sudo sh -c "(LD_LIBRARY_PATH=/usr/local/lib ./opencl-opencv-test --gtest_filter='OCL_Arithm/Add.Mat/48')"
# NG
sudo sh -c "(LD_LIBRARY_PATH=/usr/local/lib ./opencl-opencv-test --gtest_filter='OCL_Arithm/Add.Mat/0')"
sudo sh -c "(LD_LIBRARY_PATH=/usr/local/lib ./opencl-opencv-test --gtest_filter='OCL_Arithm/Add.Mat/16')"
sudo sh -c "(LD_LIBRARY_PATH=/usr/local/lib ./opencl-opencv-test --gtest_filter='OCL_Arithm/Add.Mat/40')"



