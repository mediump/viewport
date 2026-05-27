#pragma once

#include "Interface/IContextObject.hpp"
#include "Interface/IWindow.hpp"
#include "RenderingServer.hpp"

#include <memory>

// clang-format off

#define _V3D_WINDOW_ARGS    \
  int width,                \
  int height,               \
  const std::string &title

// clang-format on

namespace V3D {

class Window : public IContextObject {
  std::weak_ptr<RenderingServer> m_renderingServer;
  std::unique_ptr<IWindow> m_ptr;

public:
  Window(const std::shared_ptr<RenderingServer> &server, _V3D_WINDOW_ARGS);
  ~Window() override = default;

  void pollEvents() override;
  void destroy() override;
};

} // namespace V3D