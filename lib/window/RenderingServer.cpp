#include "RenderingServer.hpp"
#include "Window.hpp"

#include "Platform/GLFW/GLFWRenderingServer.hpp"

using namespace V3D;

RenderingServer::RenderingServer(const WindowType type) : m_windowType(type) {
  switch (m_windowType) {
  case (WindowType_GLFW):
    m_server = std::make_unique<Private::GLFWRenderingServer>();
    break;
  default:
    break;
  }
}

void RenderingServer::start() {
  if (!m_server) {
    return;
  }
  m_server->start();
}

bool RenderingServer::update() {
  if (!m_server) {
    return false;
  }

  for (auto it = m_windows.begin(); it != m_windows.end();) {
    if ((*it)->shouldClose()) {
      (*it)->destroy();
      it = m_windows.erase(it);
    } else {
      (*it)->pollEvents();
      ++it;
    }
  }

  m_server->update();
  return !m_windows.empty();
}

void RenderingServer::shutdown() {
  if (!m_server) {
    return;
  }
  m_server->shutdown();
}

std::shared_ptr<Window>
RenderingServer::createWindow(int width, int height, const std::string &title) {
  auto window = std::make_shared<Window>(m_windowType, width, height, title);
  m_windows.emplace_back(window);
  return window;
}
