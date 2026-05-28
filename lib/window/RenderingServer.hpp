#pragma once

#include "Interface/IServer.hpp"
#include "Objects/WindowObjects.hpp"

#include <memory>
#include <vector>

namespace V3D {

class Window;

class RenderingServer : public IServer
{
  WindowType m_windowType = WindowType_Headless;
  std::unique_ptr<IServer> m_server = nullptr;
  std::vector<std::shared_ptr<Window>> m_windows;

public:
  explicit RenderingServer(WindowType type);
  ~RenderingServer() override = default;

  void start() override;
  bool update() override;
  void shutdown() override;

  std::shared_ptr<Window> createWindow(int width, int height,
                                       const std::string &title);
};

}