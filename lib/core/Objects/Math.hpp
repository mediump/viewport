#pragma once

#include <cmath>

namespace V3D {

/*
  Values from: https://en.wikipedia.org/wiki/Machine_epsilon
*/
#ifdef V3D_PRECISION_DOUBLE
  typedef double real_t;
  #define V3D_ROUNDING_EPSILON 1.11e-16
#else
  typedef float real_t;
  #define V3D_ROUNDING_EPSILON 5.96e-08
#endif

#define IS_WITHIN_EPSILON(a, b) (std::abs(a - b) <= V3D_ROUNDING_EPSILON)

struct Vec2
{
  real_t x = 0.0;
  real_t y = 0.0;

  bool operator==(const Vec2 &other) const
  {
    return IS_WITHIN_EPSILON(x, other.x) &&
           IS_WITHIN_EPSILON(y, other.y);
  }
};

struct iVec2
{
  int x = 0;
  int y = 0;

  bool operator==(const iVec2 &other) const
  {
    return x == other.x && y == other.y;
  }
};

struct Size
{
  real_t width = 0.0;
  real_t height = 0.0;

  bool operator==(const Size &other) const
  {
    return IS_WITHIN_EPSILON(width, other.width) &&
           IS_WITHIN_EPSILON(height, other.height);
  }
};

struct iSize
{
  int width = 0;
  int height = 0;

  bool operator==(const iSize &other) const
  {
    return width == other.width && height == other.height;
  }
};

#undef IS_WITHIN_EPSILON

}