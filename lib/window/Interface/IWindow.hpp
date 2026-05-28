#pragma once

#include "Interface/IContextObject.hpp"

#include <string>
#include <utility>

namespace V3D {

class IWindow : public IContextObject {
protected:
  int m_width;
  int m_height;
  std::string m_title;

public:
  IWindow(const int width, const int height, std::string title)
      : m_width(width), m_height(height), m_title(std::move(title)) {}
  ~IWindow() override = default;

  virtual bool shouldClose() = 0;

  void pollEvents() override = 0;
  void destroy() override = 0;
};

} // namespace V3D