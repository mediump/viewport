#pragma once

#include "Interface/IServer.hpp"
#include <vector>

namespace V3D::Private {

class GLFWRenderingServer : public IServer {
public:
  GLFWRenderingServer() = default;
  ~GLFWRenderingServer() override = default;

  void start() override;
  bool update() override;
  void shutdown() override;
};

class GLFWVulkanServer : public GLFWRenderingServer {
public:
  GLFWVulkanServer() = default;
  ~GLFWVulkanServer() override = default;

  void start() override;
  bool update() override;
  void shutdown() override;

  std::vector<const char *> getRequiredExtensions();
};

}