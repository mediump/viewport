#pragma once

#include "Interface/IWindow.hpp"

#if defined(V3D_PLATFORM_WINDOWS)
#define VK_USE_PLATFORM_WIN32_KHR
#elif defined(V3D_PLATFORM_LINUX)
#if defined(V3D_WAYLAND_DISPLAY)
#define VK_USE_PLATFORM_WAYLAND_KHR
#elif defined(V3D_X11_DISPLAY)
// TODO: X11 Window stuff here...
#endif
#endif

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#if defined(V3D_PLATFORM_WINDOWS)
#define GLFW_EXPOSE_NATIVE_WIN32
#elif defined(V3D_PLATFORM_LINUX)
#if defined(V3D_WAYLAND_DISPLAY)
#define GLFW_EXPOSE_NATIVE_WAYLAND
#elif defined(V3D_X11_DISPLAY)
// TODO: X11 Window stuff here...
#endif
#endif
#include <GLFW/glfw3native.h>

struct GLFWwindow;

namespace V3D::Private {

class GLFWWindow : public IWindow
{
  GLFWwindow *m_glfwHandle = nullptr;

public:
  GLFWWindow(int width, int height, const std::string &title);
  ~GLFWWindow() override = default;

  bool shouldClose() override;

  void onInit() override;
  void onUpdate() override;
  void onDestroy() override;

  class Vulkan
  {
    [[nodiscard]] VkSurfaceKHR getSurface();
  };
};

} // namespace V3D::Private