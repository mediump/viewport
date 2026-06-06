#pragma once

#include "Interface/IRenderDevice.hpp"

#include <vulkan/vulkan.h>

#include <vector>

namespace V3D::Private {

class VulkanRenderDevice : public IRenderDevice
{
  VkInstance m_instance = nullptr;

public:
  explicit VulkanRenderDevice(const RenderDeviceSettings& settings);
  ~VulkanRenderDevice() override = default;

  void init() override;
  void update() override;
  void destroy() override;

private:
  void create_instance();
  static void get_glfw_extensions(VkInstanceCreateInfo *create_info);

  bool check_validation_layer_support();
  std::vector<const char*> get_required_extensions();
};

}