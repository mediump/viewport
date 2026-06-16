#pragma once

#include "Interface/IContextObject.hpp"
#include "Objects/PlatformObjects.hpp"
#include "Objects/WindowObjects.hpp"

#include <cstdint>
#include <memory>
#include <string>
#include <utility>

namespace V3D {

struct SwapChainSettings
{
  uint32_t max_frames_in_flight = 2;
};

struct SwapChainData
{};

class ISwapChain : public IContextObject
{
protected:
  std::unique_ptr<SwapChainSettings> m_settings;
  std::unique_ptr<SwapChainData> m_data;

public:
  explicit ISwapChain(const SwapChainSettings &settings)
    : m_settings(std::make_unique<SwapChainSettings>(settings))
  {
  }
  ~ISwapChain() override = default;

  void onInit() override {};
  void onUpdate() override {};
  void onDestroy() override {};
};

}