# VC4CL for Raspberry Pi 3.

Prebuilt debian packages of VC4CL for Raspberry Pi 3.
The author is doe300, https://github.com/doe300/VC4CL.

## How to Install

### Common

```
cd
git clone https://github.com/thortex/rpi3-vc4cl.git
cd rpi3-vc4cl
./000_clone_repos.sh
```

### VC4C

```
./021_install_vc4c_runtime.sh
./022_install_vc4c.sh
```

### VC4CL

```
./031_install_vc4cl_runtime.sh
./032_install_vc4cl.sh
```

## How to Build

### pre-requirements

```
./000_clone_repos.sh
./001_gcc-6.sh
./010_install_khronos_icd_loader.sh
./011_install_opencl_header1.2.sh
./012_install_clang.sh
```

### VC4C

```
./020_build_vc4c.sh
```

### VC4CL

```
./030_build_vc4cl.sh
```

### clinfo

```
040_install_clinfo.sh
```

## How to Test

### OpenCV

First of all, install OpenCV with OpenCL support. Prebuilt debian package of OpenCV which enabled OpenCL is located in https://github.com/thortex/rpi3-opencv/ 

```
cd test/opencv
./setup.sh
make
sudo sh -c '(LD_LIBRARY_PATH=gtest:/usr/local/lib ./opencl-opencv-test)'
```

If you run all test cases, it takes several hours for 16,182 tests of OpenCL tests.

You can choice test case category by specifing TEST_XX variable on make command:
```
make TEST_ORIGINAL=no \
     TEST_CORE=no \
     TEST_IMGPROC=no \
     TEST_STITCHING=no \
     TEST_PHOTO=no \
     TEST_VIDEO=no \
     TEST_FEATURE2D=no
```
