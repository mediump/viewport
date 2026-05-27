#include "Window.hpp"

#include "Platform/GLFW/GLFWWindow.hpp"
#include "RenderingServer.hpp"

V3D::Window::Window(const std::shared_ptr<RenderingServer> &server, _V3D_WINDOW_ARGS)
  : m_renderingServer(server)
{
  
}

void V3D::Window::pollEvents() {
  
}

void V3D::Window::destroy() {
  
}
