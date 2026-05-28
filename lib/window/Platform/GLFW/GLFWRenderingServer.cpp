#include "GLFWRenderingServer.hpp"

#include "Log/Log.hpp"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

V3D::Private::GLFWRenderingServer::GLFWRenderingServer() = default;

void V3D::Private::GLFWRenderingServer::start() {
  Log::print("[GLFWRenderingServer]: Startup");
  glfwInit();
}

bool V3D::Private::GLFWRenderingServer::update() {
  Log::print("[GLFWRenderingServer]: Update");
  return true;
}

void V3D::Private::GLFWRenderingServer::shutdown() {
  Log::print("[GLFWRenderingServer]: Shutdown");
  glfwTerminate();
}
