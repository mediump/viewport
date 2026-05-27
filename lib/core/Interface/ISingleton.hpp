#pragma once

#include <mutex>

// clang-format off

#define _V3D_DEL_COPY_MOVE(T)       \
  T(const T&) = delete;             \
  T& operator=(const T&) = delete;  \
  T(T&&) = delete;                  \
  T& operator=(T&&) = delete;

// clang-format on

namespace V3D {

template <typename T> class ISingleton {
protected:
  ISingleton() = default;
  virtual ~ISingleton() = default;

  mutable std::mutex m_mutex;

  static T &instance() {
    static T inst;
    return inst;
  }

public:
  _V3D_DEL_COPY_MOVE(ISingleton)

  class Accessor {
  private:
    T *m_instance;
    std::unique_lock<std::mutex> m_lock;

  public:
    Accessor(T *instance, std::mutex &mutex)
        : m_instance(instance), m_lock(mutex) {}

    T *operator->() { return m_instance; }
  };

  static Accessor getSingleton() {
    T &inst = instance();
    return Accessor(&inst, inst.m_mutex);
  }
};

} // namespace V3D