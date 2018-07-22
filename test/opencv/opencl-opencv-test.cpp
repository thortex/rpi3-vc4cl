#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <CL/cl.h>
#include <opencv2/core/ocl.hpp>
#include <opencv2/core/utility.hpp>
#include <opencv2/video.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <gtest/gtest.h>

using namespace std;
using namespace cv;

#define VC4CL_OCL_1_1 1
#define VC4CL_OCL_1_2 1
#undef  VC4CL_OCL_2_0

TEST(OpenCV, haveOpenCL) {
  // check whether OpenCL device is found.
  ASSERT_GE(ocl::haveOpenCL(), 1);
}

TEST(OpenCV, Context_create) {
  ocl::Context ctx;
  int ret = ctx.create(ocl::Device::TYPE_GPU);
  ASSERT_NE(ret, 0);
}

TEST(OpenCV, Context_device) { 
  ocl::Context ctx;
  int ret = ctx.create(ocl::Device::TYPE_GPU);
  ASSERT_NE(ret, 0);
  ocl::Device device = ctx.device(0);
  ASSERT_NE(device.name(), "");
  ASSERT_NE(device.extensions(), "");
  ASSERT_NE(device.version(), "");
  ASSERT_NE(device.vendorName(), "");
  ASSERT_NE(device.OpenCL_C_Version(), "");
  ASSERT_GE(device.deviceVersionMajor(), 0);
  ASSERT_GE(device.deviceVersionMinor(), 0);
  ASSERT_NE(device.driverVersion(), "");
  ASSERT_EQ(device.addressBits(), 32);
  ASSERT_EQ(device.available(), true);
  ASSERT_EQ(device.compilerAvailable(), true);
  ASSERT_EQ(device.linkerAvailable(), true);
#ifdef VC4CL_OCL_1_2  
  ASSERT_GE(device.doubleFPConfig(), 0);
#endif
  ASSERT_GE(device.singleFPConfig(), 0);
  ASSERT_GE(device.halfFPConfig(), 0);
  ASSERT_EQ(device.endianLittle(), true);
  ASSERT_GE(device.executionCapabilities(), 1);
  ASSERT_GE(device.globalMemCacheSize(), 1);
  ASSERT_GE(device.globalMemCacheType(), 1);
  ASSERT_GE(device.globalMemCacheLineSize(), 1);
  ASSERT_GE(device.globalMemSize(), 1);
  ASSERT_GE(device.localMemType(), 1);
#ifdef VC4CL_OCL_1_1
  ASSERT_GE(device.hostUnifiedMemory(), true);
#endif
  ASSERT_GE(device.imageSupport(), 0);
  ASSERT_GE(device.imageFromBufferSupport(), 0);
  ASSERT_GE(device.image2DMaxWidth(), 1);
  ASSERT_GE(device.image2DMaxHeight(), 1);
  ASSERT_GE(device.image3DMaxWidth(), 1);
  ASSERT_GE(device.image3DMaxHeight(), 1);
  ASSERT_GE(device.image3DMaxDepth(), 1);
#ifdef VC4CL_OCL_1_2
  ASSERT_GE(device.imageMaxBufferSize(), 1);
  ASSERT_GE(device.imageMaxArraySize(), 1);
  ASSERT_GE(device.memBaseAddrAlign(), 1);
#endif
  ASSERT_GE(device.vendorID(), 0);
  ASSERT_GE(device.maxClockFrequency(), 200);
  ASSERT_GE(device.maxComputeUnits(), 1);
  ASSERT_GE(device.maxConstantArgs(), 1);
  ASSERT_GE(device.maxConstantBufferSize(), 1);
  ASSERT_GE(device.maxMemAllocSize(), 1);
  ASSERT_GE(device.maxParameterSize(), 0);
  ASSERT_GE(device.maxReadImageArgs(), 0);
  ASSERT_GE(device.maxWriteImageArgs(), 0);
  ASSERT_GE(device.maxSamplers(), 1);
  ASSERT_GE(device.maxWorkGroupSize(), 1);
  ASSERT_GE(device.maxWorkItemDims(), 1);
#ifdef VC4CL_OCL_1_1
  ASSERT_GE(device.preferredVectorWidthHalf(), 0);
  ASSERT_GE(device.nativeVectorWidthChar(), 1);
  ASSERT_GE(device.nativeVectorWidthShort(), 1);
  ASSERT_GE(device.nativeVectorWidthInt(), 1);
  ASSERT_GE(device.nativeVectorWidthLong(), 0);
  ASSERT_GE(device.nativeVectorWidthFloat(), 1);
  ASSERT_GE(device.nativeVectorWidthDouble(), 0);
  ASSERT_GE(device.nativeVectorWidthHalf(), 0);
#endif
  ASSERT_GE(device.preferredVectorWidthChar(), 1);
  ASSERT_GE(device.preferredVectorWidthShort(), 1);
  ASSERT_GE(device.preferredVectorWidthInt(), 1);
  ASSERT_GE(device.preferredVectorWidthLong(), 0);
  ASSERT_GE(device.preferredVectorWidthFloat(), 1);
  ASSERT_GE(device.preferredVectorWidthDouble(), 0);
  ASSERT_GE(device.printfBufferSize(), 0);
  ASSERT_GE(device.profilingTimerResolution(), 0);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

