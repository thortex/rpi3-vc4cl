#!/bin/bash -x

(cd ~/rpi3-vc4cl/VC4C && git log |head -1) > vc4cl.ver
(cd ~/rpi3-vc4cl/VC4CL && git log |head -1) >> vc4cl.ver
(cd ~/rpi3-vc4cl/VC4CLStdLib && git log |head -1) >> vc4cl.ver

sudo sh -c "(LD_LIBRARY_PATH=/usr/local/lib ./opencl-opencv-test --gtest_filter='$1')" 2>&1 \
    | tee test-${1/\*/log}


