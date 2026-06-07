#include "GLFWWindow.hpp"
#include "Log/Log.hpp"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

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
    m_title, m_width, m_height);

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
