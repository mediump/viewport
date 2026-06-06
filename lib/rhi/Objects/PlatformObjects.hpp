#pragma once

// Versioning
#define V3D_MAKE_VERSION(major, minor, patch)  \
  (((major) << 16) | ((minor) << 8) | (patch))

#define V3D_VERSION_MAJOR(version) (((version) >> 16) & 0xFF)
#define V3D_VERSION_MINOR(version) (((version) >> 8) & 0xFF)
#define V3D_VERSION_PATCH(version) ((version) & 0xFF)
// ---

namespace V3D {

enum GraphicsPlatform {
  GraphicsPlatform_None = -1,
  GraphicsPlatform_Vulkan = 0
};

}