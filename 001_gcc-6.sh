#!/bin/sh -x

V=6
sudo apt-get install gcc-$V g++-$V
sudo unlink /usr/bin/gcc
sudo unlink /usr/bin/g++

sudo ln -s /usr/bin/gcc-$V /usr/bin/gcc
sudo ln -s /usr/bin/g++-$V /usr/bin/g++
