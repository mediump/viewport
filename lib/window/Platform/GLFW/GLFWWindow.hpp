#pragma once

#include "Interface/IWindow.hpp"

struct GLFWwindow;

namespace V3D::Private {

class GLFWWindow : public IWindow {
  GLFWwindow *m_glfwHandle = nullptr;

public:
  GLFWWindow(int width, int height, const std::string &title);
  ~GLFWWindow() override = default;

  bool shouldClose() override;

  void update() override;
  void destroy() override;
};

} // namespace V3D::Private