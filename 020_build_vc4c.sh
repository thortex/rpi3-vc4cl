#!/bin/bash -x
#
# Compiler for the VC4CL OpenCL implementation
#
cd VC4C
cmake .
make
sudo checkinstall -D \
     --install=yes \
     --pkgname=vc4c \
     --pkgversion=0.4 \
     --provides=vc4c
