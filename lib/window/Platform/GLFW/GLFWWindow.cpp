#include "GLFWWindow.hpp"

using namespace V3D::Private;

GLFWWindow::GLFWWindow(int width, int height, const std::string &title)
    : IWindow(width, height, title) {
  m_glfwHandle =
      glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr);
}

void GLFWWindow::pollEvents() { glfwPollEvents(); }

void GLFWWindow::destroy() {
  glfwDestroyWindow(m_glfwHandle);
  m_glfwHandle = nullptr;
}
