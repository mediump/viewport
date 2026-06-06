#include "GLFWWindow.hpp"
#include "Log/Log.hpp"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

using namespace V3D::Private;

GLFWWindow::GLFWWindow(int width, int height, const std::string &title)
  : IWindow(width, height, title)
{
  Log::print("[GLFWWindow]: Construction");

  m_glfwHandle = glfwCreateWindow(
    m_width, m_height, m_title.c_str(), nullptr, nullptr);
}

bool GLFWWindow::shouldClose()
{
  return glfwWindowShouldClose(m_glfwHandle);
}

void GLFWWindow::update()
{
  Log::print("[GLFWWindow]: Poll Events");

  glfwPollEvents();
}

void GLFWWindow::destroy()
{
  Log::print("[GLFWWindow]: Destroy");
  
  glfwDestroyWindow(m_glfwHandle);
  m_glfwHandle = nullptr;
}
