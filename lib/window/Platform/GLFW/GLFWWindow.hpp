#pragma once

#include "Interface/IWindow.hpp"

#include <GLFW/glfw3.h>

namespace V3D::Private {

class GLFWWindow : public IWindow {
  GLFWwindow *m_glfwHandle = nullptr;

public:
  GLFWWindow(int width, int height, const std::string &title);
  ~GLFWWindow() override = default;

  void pollEvents() override;
  void destroy() override;
};

} // namespace V3D::Private