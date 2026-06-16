#pragma once

// Versioning
#define V3D_MAKE_VERSION(major, minor, patch)  \
  (((major) << 16) | ((minor) << 8) | (patch))

#define V3D_VERSION_MAJOR(version) (((version) >> 16) & 0xFF)
#define V3D_VERSION_MINOR(version) (((version) >> 8) & 0xFF)
#define V3D_VERSION_PATCH(version) ((version) & 0xFF)
// ---

// Linux session manager
#define V3D_WAYLAND_DISPLAY 0
#define V3D_X11_DISPLAY 0

#if defined(WAYLAND_DISPLAY)
  #define V3D_WAYLAND_DISPLAY 1
#elif defined(X11)
  #define V3D_X11_DISPLAY 1
#endif
// ---

namespace V3D {

enum GraphicsPlatform {
  GraphicsPlatform_None = -1,
  GraphicsPlatform_Vulkan = 0
};

}