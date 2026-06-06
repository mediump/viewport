#pragma once

#include "spdlog/fmt/fmt.h"

#ifndef __FUNCTION_NAME__
#ifdef _WIN32
#define __FUNCTION_NAME__ __FUNCTION__
#else
#define __FUNCTION_NAME__ __func__
#endif
#endif

namespace V3D::Private {

enum ErrorCode
{
  ErrorCode_None = 0,
  ErrorCode_RenderDeviceCreationFailed,
};

class NotImplemented : public std::logic_error
{
public:
  NotImplemented(std::string e)
    : std::logic_error(std::move(e)) {};
};

}

#define FUNCTION_NOT_IMPLEMENTED NotImplemented(std::string(__FUNCTION_NAME__).append(" is not implemented."))