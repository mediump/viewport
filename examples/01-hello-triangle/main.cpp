#include <iostream>

#include "Log/Log.hpp"
#include "RenderingServer.hpp"

int main() {
  V3D::Log::print("Example startup");

  const auto renderingServer =
      std::make_unique<V3D::RenderingServer>(V3D::WindowType_GLFW);

  renderingServer->start();
  renderingServer->createWindow(256, 256, "Test Window");

  while (renderingServer->update()) {
    V3D::Log::print("[User]: Update Loop");
  }

  renderingServer->shutdown();
}
