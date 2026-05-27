#pragma once

#include "Interface/ISingleton.hpp"

#include "spdlog/spdlog.h"

#define V3D_DEFAULT_LOG_PATTERN                                                \
  "[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v"

#define _V3D_VARG_TEMPLATE(Args) template <typename... Args>

namespace V3D {

class Log : public ISingleton<Log> {
  friend class ISingleton<Log>;

  enum LogLevel {
    LogLevel_Info,
    LogLevel_Warn,
    LogLevel_Error,
  };

private:
  Log() = default;

public:
  _V3D_VARG_TEMPLATE(Args)
  static void print(const char *fmt, Args... args)
  {
    Log::getSingleton()->log(LogLevel_Info, fmt, args...);
  }

  _V3D_VARG_TEMPLATE(Args)
  static void warn(const char *fmt, Args... args)
  {
    Log::getSingleton()->log(LogLevel_Warn, fmt, args...);
  }

  _V3D_VARG_TEMPLATE(Args)
  static void error(const char *fmt, Args... args)
  {
    Log::getSingleton()->log(LogLevel_Error, fmt, args...);
  }

private:
  spdlog::level::level_enum get_level(LogLevel level)
  {
    switch (level) {
      case LogLevel_Info:
        return spdlog::level::info;
      case LogLevel_Warn:
        return spdlog::level::warn;
      case LogLevel_Error:
        return spdlog::level::err;
      default:
        spdlog::warn("Undefined log level");
        return spdlog::level::info;
    }
  }

  _V3D_VARG_TEMPLATE(Args)
  void log(LogLevel level, const char *fmt, Args... args)
  {
    spdlog::log(get_level(level), fmt, args...);
  }
};

} // namespace V3D