{
 global:
  clGetPlatformIDs;
  clGetPlatformInfo;
  clGetDeviceIDs;
  clGetDeviceInfo;
  clCreateSubDevices;
  clRetainDevice;
  clReleaseDevice;
  clCreateContext;
  clCreateContextFromType;
  clRetainContext;
  clReleaseContext;
  clGetContextInfo;
  clCreateCommandQueue;
  clRetainCommandQueue;
  clReleaseCommandQueue;
  clGetCommandQueueInfo;
  clCreateBuffer;
  clCreateSubBuffer;
  clCreateImage;
  clRetainMemObject;
  clReleaseMemObject;
  clGetSupportedImageFormats;
  clGetMemObjectInfo;
  clGetImageInfo;
  clSetMemObjectDestructorCallback;
  clCreateSampler;
  clRetainSampler;
  clReleaseSampler;
  clGetSamplerInfo;
  clCreateProgramWithSource;
  clCreateProgramWithBinary;
  clCreateProgramWithBuiltInKernels;
  clRetainProgram;
  clReleaseProgram;
  clBuildProgram;
  clCompileProgram;
  clLinkProgram;
  clUnloadPlatformCompiler;
  clGetProgramInfo;
  clGetProgramBuildInfo;
  clCreateKernel;
  clCreateKernelsInProgram;
  clRetainKernel;
  clReleaseKernel;
  clSetKernelArg;
  clGetKernelInfo;
  clGetKernelArgInfo;
  clGetKernelWorkGroupInfo;
  clWaitForEvents;
  clGetEventInfo;
  clCreateUserEvent;
  clRetainEvent;
  clReleaseEvent;
  clSetUserEventStatus;
  clSetEventCallback;
  clGetEventProfilingInfo;
  clFlush;
  clFinish;
  clEnqueueReadBuffer;
  clEnqueueReadBufferRect;
  clEnqueueWriteBuffer;
  clEnqueueWriteBufferRect;
  clEnqueueFillBuffer;
  clEnqueueCopyBuffer;
  clEnqueueCopyBufferRect;
  clEnqueueReadImage;
  clEnqueueWriteImage;
  clEnqueueFillImage;
  clEnqueueCopyImage;
  clEnqueueCopyImageToBuffer;
  clEnqueueCopyBufferToImage;
  clEnqueueMapBuffer;
  clEnqueueMapImage;
  clEnqueueUnmapMemObject;
  clEnqueueMigrateMemObjects;
  clEnqueueNDRangeKernel;
  clEnqueueTask;
  clEnqueueNativeKernel;
  clEnqueueMarkerWithWaitList;
  clEnqueueBarrierWithWaitList;
  clSetCommandQueueProperty;
  clCreateImage2D;
  clCreateImage3D;
  clEnqueueMarker;
  clEnqueueWaitForEvents;
  clEnqueueBarrier;
  clUnloadCompiler;
  clEnqueueBroadcastBuffer;
  clEnqueueAlltoAllBuffer;
  clIcdGetPlatformIDsKHR;
  clGetExtensionFunctionAddress;
  clGetExtensionFunctionAddressForPlatform;
 local:
  *;
};
