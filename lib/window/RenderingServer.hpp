#pragma once

#include "Interface/IServer.hpp"
#include "Objects/WindowObjects.hpp"

#include <vector>

namespace V3D {

class RenderingServer : public IServer {
  WindowType m_windowType;

public:
  RenderingServer(WindowType type);
  ~RenderingServer() override = default;

  void start() override;
  void update() override;
  void shutdown() override;
};

}