#pragma once

#include "Interface/IContextObject.hpp"
#include "Objects/Settings.hpp"

#include "WindowManager.hpp"
#include "Scene.hpp"

namespace V3D {

class ContextPrivate;

class Context : public IContextObject
{
public:
  Context(const Settings &settings);
  ~Context() = default;

  void onInit() override;
  void onUpdate() override;
  void onDestroy() override;

  [[nodiscard]] Settings settings();
  [[nodiscard]] bool shouldClose();

  [[nodiscard]] WindowManager *windowManager();
  [[nodiscard]] Scene *scene();

private:
  std::shared_ptr<ContextPrivate> m_pImpl;
};

}