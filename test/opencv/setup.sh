#!/bin/bash -x

OPENCV_VER=3.4.2

sudo apt-get install googletest libgtest-dev

mkdir -p gtest && cd gtest && cmake /usr/src/gtest -DBUILD_SHARED_LIBS=ON && make

