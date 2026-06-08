#pragma once

#include "Interface/IContextObject.hpp"
#include "Objects/Math.hpp"

#include <string>
#include <utility>

namespace V3D {

class IWindow : public IContextObject
{
public:
  IWindow(const int width, const int height, std::string title)
    : m_width(width)
    , m_height(height)
    , m_title(std::move(title))
  {
  }
  ~IWindow() override = default;

  virtual bool shouldClose() = 0;

  void onInit() override = 0;
  void onUpdate() override = 0;
  void onDestroy() override = 0;

protected:
  int m_width;
  int m_height;
  std::string m_title;
};

} // namespace V3D