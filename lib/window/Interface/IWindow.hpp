#pragma once

#include "Interface/IContextObject.hpp"

#include <string>

namespace V3D {

class IWindow : public IContextObject {
protected:
  int m_width;
  int m_height;
  std::string m_title;

public:
  IWindow(int width, int height, const std::string &title)
      : m_width(width), m_height(height), m_title(title) {}
  ~IWindow() override = default;

  void pollEvents() override;
  void destroy() override;
};

} // namespace V3D