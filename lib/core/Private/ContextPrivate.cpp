#include "ContextPrivate.hpp"

using namespace V3D;

ContextPrivate::ContextPrivate(const Settings &settings)
  : IContextObject()
  , m_settings(settings)
  , m_shouldClose(m_shouldClose)
  , m_windowManager(nullptr)
  , m_scene(nullptr)
{
}

void ContextPrivate::onInit() {
    m_windowManager = std::make_unique<WindowManager>(this);
    m_windowManager->init();

    m_scene = std::make_unique<Scene>();
    m_scene->init();
}

void ContextPrivate::onUpdate() {
    m_windowManager->update();
    m_scene->update();
}

void ContextPrivate::onDestroy() {
    m_windowManager->destroy();
    m_windowManager.reset();

    m_scene->destroy();
    m_scene.reset();
}

Settings ContextPrivate::settings()
{
  return m_settings;
}

bool ContextPrivate::shouldClose()
{
  return m_shouldClose;
}

WindowManager *ContextPrivate::windowManager()
{
  return m_windowManager.get();
}

Scene *ContextPrivate::scene()
{
  return m_scene.get();
}
