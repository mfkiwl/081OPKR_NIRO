#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef __APPLE__
#include <OpenCL/cl.h>
#else
#include <CL/cl.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define CL_CHECK(_expr)          \
  do {                           \
    assert(CL_SUCCESS == _expr); \
  } while (0)

#define CL_CHECK_ERR(_expr)           \
  ({                                  \
    cl_int err = CL_INVALID_VALUE;    \
    __typeof__(_expr) _ret = _expr;   \
    assert(_ret&& err == CL_SUCCESS); \
    _ret;                             \
  })

cl_device_id cl_get_device_id(cl_device_type device_type);
cl_program cl_program_from_file(cl_context ctx, cl_device_id device_id, const char* path, const char* args);
const char* cl_get_error_string(int err);

#ifdef __cplusplus
}
#endif