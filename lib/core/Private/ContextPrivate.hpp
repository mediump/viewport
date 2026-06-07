#pragma once

#include "Interface/IContextObject.hpp"
#include "Objects/Settings.hpp"

#include "WindowManager.hpp"
#include "Scene.hpp"

#include <memory>

namespace V3D {

class ContextPrivate : public IContextObject
{
public:
    explicit ContextPrivate(const Settings &settings);
    ~ContextPrivate() override = default;

    void onInit() override;
    void onUpdate() override;
    void onDestroy() override;

    [[nodiscard]] Settings settings();
    [[nodiscard]] bool shouldClose();

    [[nodiscard]] WindowManager *windowManager();
    [[nodiscard]] Scene *scene();

private:
    Settings m_settings;
    bool m_shouldClose;

    std::unique_ptr<WindowManager> m_windowManager;
    std::unique_ptr<Scene> m_scene;
};

}