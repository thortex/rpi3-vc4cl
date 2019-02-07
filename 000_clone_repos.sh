#!/bin/sh -x

if [ ! -d VC4CL ] ; then
    git clone https://github.com/doe300/VC4CL.git
fi

if [ ! -d VC4C ] ; then
    git clone https://github.com/doe300/VC4C.git
fi

if [ ! -d VC4CLStdLib ] ; then
    git clone https://github.com/doe300/VC4CLStdLib.git
fi

(cd VC4CL && git checkout master && git pull)
(cd VC4C && git checkout master && git pull)
(cd VC4CLStdLib && git checkout master && git pull)
