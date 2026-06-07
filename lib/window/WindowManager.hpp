#pragma once

#include "Interface/IContextObject.hpp"

#include <memory>

namespace V3D {

class ContextPrivate;

class WindowManager : public IContextObject 
{
public:
    explicit WindowManager(ContextPrivate *context);
    ~WindowManager() override = default;

    void onInit() override;
    void onUpdate() override;
    void onDestroy() override;

private:
    ContextPrivate *m_context;
};

}