#pragma once

#include "Interface/IContextObject.hpp"
#include "Objects/PlatformObjects.hpp"
#include "Objects/WindowObjects.hpp"

#include <cstdint>
#include <memory>
#include <string>
#include <utility>

namespace V3D {

struct RenderDeviceSettings
{
  GraphicsPlatform platform = GraphicsPlatform_Vulkan;
  WindowType window_type = WindowType_Normal;
  std::string app_name = "V3D App";
  uint32_t app_version = V3D_MAKE_VERSION(1, 0, 0);
  std::string engine_name = "V3D Engine";
  uint32_t engine_version = V3D_MAKE_VERSION(1, 0, 0);
};

class IRenderDevice : public IContextObject {
protected:
  std::unique_ptr<RenderDeviceSettings> m_settings;

public:
  explicit IRenderDevice(const RenderDeviceSettings& settings)
    : m_settings(std::make_unique<RenderDeviceSettings>(settings))
  {
  }
  ~IRenderDevice() override = default;

  void init() override;
  void update() override;
  void destroy() override;
};

}