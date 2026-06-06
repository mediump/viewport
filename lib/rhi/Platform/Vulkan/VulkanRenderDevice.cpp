#include "VulkanRenderDevice.hpp"

#include "Log/Log.hpp"
#include "Objects/ErrorCodes.hpp"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

using namespace V3D::Private;

const std::vector VK_VALIDATION_LAYER_LIST = { "VK_LAYER_KHRONOS_validation" };

VulkanRenderDevice::VulkanRenderDevice(const RenderDeviceSettings &settings)
  : IRenderDevice(settings)
{
}

void VulkanRenderDevice::init()
{
  Log::print("[Vulkan]: Creating render device...");
  create_instance();
}

void VulkanRenderDevice::update() {}

void VulkanRenderDevice::destroy()
{
  vkDestroyInstance(m_instance, nullptr);
}

void VulkanRenderDevice::create_instance()
{
  const uint32_t app_major_v = V3D_VERSION_MAJOR(m_settings->app_version);
  const uint32_t app_minor_v = V3D_VERSION_MINOR(m_settings->app_version);
  const uint32_t app_patch_v = V3D_VERSION_PATCH(m_settings->app_version);

  const uint32_t engine_major_v = V3D_VERSION_MAJOR(m_settings->engine_version);
  const uint32_t engine_minor_v = V3D_VERSION_MINOR(m_settings->engine_version);
  const uint32_t engine_patch_v = V3D_VERSION_PATCH(m_settings->engine_version);

  VkApplicationInfo app_info = {};
  app_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
  app_info.pApplicationName = m_settings->app_name.c_str();
  app_info.applicationVersion = VK_MAKE_VERSION(
    app_major_v, app_minor_v, app_patch_v);
  app_info.pEngineName = m_settings->engine_name.c_str();
  app_info.engineVersion = VK_MAKE_VERSION(
    engine_major_v, engine_minor_v, engine_patch_v);
  app_info.apiVersion = VK_API_VERSION_1_2;

  VkInstanceCreateInfo create_info = {};
  create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
  create_info.pApplicationInfo = &app_info;

#ifdef V3D_DEBUG
  if (!check_validation_layer_support()) {
    Log::error("[Vulkan]: Validation layers requested but not available.");
  } else {
    create_info.enabledExtensionCount = static_cast<uint32_t>(
      VK_VALIDATION_LAYER_LIST.size());
    create_info.ppEnabledLayerNames = VK_VALIDATION_LAYER_LIST.data();
  }
#else
  create_info.enabledLayerCount = 0;
#endif

  switch (m_settings->window_type) {
    case WindowType_Normal:
      get_glfw_extensions(&create_info);
      break;
    default:
      break;
  }

  if (vkCreateInstance(&create_info, nullptr, &m_instance) != VK_SUCCESS) {
    Log::error("[Vulkan]: Failed to create Vulkan instance");
    V3D_EXIT(ErrorCode_RenderDeviceCreationFailed);
  }
}

void VulkanRenderDevice::get_glfw_extensions(VkInstanceCreateInfo *create_info)
{
  uint32_t glfw_extension_count = 0;
  const char **glfw_extensions = glfwGetRequiredInstanceExtensions(
    &glfw_extension_count);

  std::vector<const char *> required_extensions(glfw_extension_count + 1);

  for (uint32_t i = 0; i < glfw_extension_count; i++) {
    required_extensions[i] = glfw_extensions[i];
  }
  required_extensions[glfw_extension_count] =
    VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME;

  create_info->flags |= VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR;
  create_info->enabledExtensionCount = glfw_extension_count;
  create_info->ppEnabledExtensionNames = glfw_extensions;
}

bool VulkanRenderDevice::check_validation_layer_support()
{
  uint32_t layer_count;
  vkEnumerateInstanceLayerProperties(&layer_count, nullptr);

  std::vector<VkLayerProperties> available_layers(layer_count);
  vkEnumerateInstanceLayerProperties(&layer_count, available_layers.data());

  for (const char *layer_name : VK_VALIDATION_LAYER_LIST) {
    bool layer_found = false;

    for (const auto &layer_properties : available_layers) {
      if (strcmp(layer_name, layer_properties.layerName) == 0) {
        layer_found = true;
        break;
      }
    }

    if (!layer_found) {
      return false;
    }
  }

  return true;
}

std::vector<const char *> VulkanRenderDevice::get_required_extensions()
{
  uint32_t glfw_extension_count = 0;
  throw FUNCTION_NOT_IMPLEMENTED;
}