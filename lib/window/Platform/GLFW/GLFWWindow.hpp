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

  void onInit() override;
  void onUpdate() override;
  void onDestroy() override;
};

} // namespace V3D::Private