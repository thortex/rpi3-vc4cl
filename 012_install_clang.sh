#!/bin/sh -x
CLANG_VER=3.9
sudo apt-get install \
     clang-${CLANG_VER} \
     clang-format-${CLANG_VER} \
     llvm-${CLANG_VER} \
     llvm-${CLANG_VER}-runtime

