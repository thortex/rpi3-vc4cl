#!/bin/sh -x

cd VC4CL
cmake .
make
sudo checkinstall -D \
     --install=yes \
     --pkgname=vc4cl \
     --pkgversion=0.4 \
     --provides=vc4cl

