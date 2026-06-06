#include "GLFWRenderingServer.hpp"

#include "Log/Log.hpp"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

using namespace V3D::Private;

/*
  GLFWRenderingServer
*/

void GLFWRenderingServer::start()
{
  Log::print("[GLFWRenderingServer]: Startup");
  glfwInit();
}

bool GLFWRenderingServer::update()
{
  Log::print("[GLFWRenderingServer]: Update");
  return true;
}

void GLFWRenderingServer::shutdown()
{
  Log::print("[GLFWRenderingServer]: Shutdown");
  glfwTerminate();
}

/*
  GLFWVulkanServer
*/

void GLFWVulkanServer::start() {}

bool GLFWVulkanServer::update() {}

void GLFWVulkanServer::shutdown() {}

std::vector<const char *> GLFWVulkanServer::getRequiredExtensions()
{
  uint32_t glfw_extension_count = 0;
  const char **glfw_extensions;

  glfw_extensions = glfwGetRequiredInstanceExtensions(&glfw_extension_count);
  std::vector<const char *> out_extensions(glfw_extension_count);

  for (uint32_t i = 0; i < glfw_extension_count; i++) {
    out_extensions[i] = glfw_extensions[i];
  }

  return out_extensions;
}
