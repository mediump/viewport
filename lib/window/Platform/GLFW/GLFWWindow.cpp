#include "GLFWWindow.hpp"
#include "Log/Log.hpp"

using namespace V3D::Private;

GLFWWindow::GLFWWindow(int width, int height, const std::string &title)
  : IWindow(width, height, title)
{
}

bool GLFWWindow::shouldClose()
{
  return glfwWindowShouldClose(m_glfwHandle);
}

void GLFWWindow::onInit()
{
  Log::print("[GLFWWindow]: Creating window ['{}', ({}, {})]",
             m_title,
             m_width,
             m_height);

  m_glfwHandle = glfwCreateWindow(
    m_width, m_height, m_title.c_str(), nullptr, nullptr);
}

void GLFWWindow::onUpdate()
{
  Log::print("[GLFWWindow]: Poll Events");

  glfwPollEvents();
}

void GLFWWindow::onDestroy()
{
  Log::print("[GLFWWindow]: Destroy");

  glfwDestroyWindow(m_glfwHandle);
  m_glfwHandle = nullptr;
}

VkSurfaceKHR GLFWWindow::Vulkan::getSurface()
{
  VkSurfaceKHR surface;

#if defined(V3D_PLATFORM_WINDOWS)
  VkWin32SurfaceCreateInfoKHR create_info = {};
  create_info.sType = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
  create_info.hwnd = glfwGetWin32Window(m_glfwHandle);
  create_info.hinstance = GetModuleHandle(nullptr);

  if (vkCreateWin32SurfaceKHR(instance, &create_info, nullptr, &surface) !=
      VK_SUCCESS) {
    throw Log::error("Failed to create VkSurfaceKHR (Win32).");
    return nullptr;
  }
#elif defined(V3D_PLATFORM_LINUX)
#if defined(V3D_WAYLAND_DISPLAY)
  VkWaylandSurfaceCreateInfoKHR create_info = {};
  create_info.sType = VK_STRUCTURE_TYPE_WAYLAND_SURFACE_CREATE_INFO;
  create_info.hwnd = glfwGetWaylandWindow(m_glfwHandle);

  if (vkCreateWaylandSurfaceKHR(instance, &create_info, nullptr, &surface) !=
      VK_SUCCESS) {
    throw Log::error("Failed to create VkSurfaceKHR (Wayland).");
    return nullptr;
  }
#elif defined(V3D_X11_DISPLAY)
  // TODO: X11 stuff here
  // ...
#endif
#endif

  // TODO: MacOS stuff here

  return surface;
}
