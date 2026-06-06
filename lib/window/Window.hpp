#pragma once

#include "Interface/IContextObject.hpp"
#include "Interface/IWindow.hpp"
#include "Objects/WindowObjects.hpp"

#include <memory>

// clang-format off

#define V3D_WINDOW_ARGS    \
  int width,                \
  int height,               \
  const std::string &title

// clang-format on

namespace V3D {

class Window : public IContextObject {
  std::unique_ptr<IWindow> m_ptr;
  WindowType m_type;
  bool m_shouldClose;

public:
  explicit Window(WindowType type, int width, int height,
                  const std::string &title);
  ~Window() override = default;

  [[nodiscard]] bool shouldClose() const;

  void update() override;
  void destroy() override;
};

} // namespace V3D