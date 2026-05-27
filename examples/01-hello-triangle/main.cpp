#include <iostream>

#include "Log/Log.hpp"

int main() {
  V3D::Log::print("Print test {}", 123456789);
  V3D::Log::warn("Warning test {}", 123456789);
  V3D::Log::error("Error test {}", 123456789);
}
