#pragma once

#include "Interface/IContextObject.hpp"

namespace V3D {

class Scene : public IContextObject
{
public:
    Scene() = default;
    ~Scene() override = default;

    void init() override;
    void update() override;
    void destroy() override;
};

}