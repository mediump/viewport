#include "Window.hpp"

#include "Platform/GLFW/GLFWWindow.hpp"
#include "RenderingServer.hpp"

using namespace V3D;

Window::Window(const WindowType type, int width, int height, const std::string& title)
  : m_type(type)
{
  switch (m_type)
  {
  case (WindowType_GLFW):
    m_ptr = std::make_unique<Private::GLFWWindow>(width, height, title);
    break;
  default: break;
  }
}

bool Window::shouldClose() const {
  return m_ptr->shouldClose();
}

void Window::pollEvents()
{
  if (m_ptr) {
    m_ptr->pollEvents();
  }
}

void Window::destroy()
{
  if (m_ptr) {
    m_ptr->destroy();
    m_ptr.reset();
  }
}
