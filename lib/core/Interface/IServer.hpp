#pragma once

namespace V3D {

/* Manages a runtime context */
class IServer {
public:
  virtual ~IServer() = default;

  virtual void start() = 0;
  virtual bool update() = 0;
  virtual void shutdown() = 0;
};

} // namespace V3D