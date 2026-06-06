#pragma once

namespace V3D {

enum BackendType {
    Backend_None = -1,
    Backend_Vulkan = 0
};

enum PlatformType {
    Platform_External = -1,
    Platform_GLFW = 0
};

struct Settings {
    BackendType backend = Backend_Vulkan;
    PlatformType platform = Platform_GLFW;

    bool operator==(const Settings &other) const
    {
        return backend == other.backend &&
               platform == other.platform;
    }
};

}