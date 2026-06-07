#include "Context.hpp"

#include "ContextPrivate.hpp"

using namespace V3D;

Context::Context(const Settings &settings)
  : IContextObject()
  , m_pImpl(std::make_shared<ContextPrivate>(settings))
{
}

void Context::onInit() {
    m_pImpl->init();
}

void Context::onUpdate() {
    m_pImpl->update();
}

void Context::onDestroy() {
    m_pImpl->destroy();
    m_pImpl.reset();
}

Settings Context::settings()
{
  return m_pImpl->settings();
}

bool Context::shouldClose()
{
  return m_pImpl->shouldClose();
}

WindowManager *Context::windowManager()
{
  return m_pImpl->windowManager();
}

Scene *Context::scene()
{
  return m_pImpl->scene();
}
