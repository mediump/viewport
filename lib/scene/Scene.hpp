#pragma once

#include "Interface/IContextObject.hpp"

namespace V3D {

class Scene : public IContextObject
{
public:
    Scene() = default;
    ~Scene() override = default;

    void onInit() override;
    void onUpdate() override;
    void onDestroy() override;
};

}