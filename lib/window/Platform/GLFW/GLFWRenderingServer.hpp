#pragma once

#include "Interface/IServer.hpp"

namespace V3D::Private {

class GLFWRenderingServer : public IServer {

public:
  GLFWRenderingServer();
  ~GLFWRenderingServer() override = default;

  void start() override;
  void update() override;
  void shutdown() override;
};

}