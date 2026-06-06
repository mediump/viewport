#pragma once

/* Object that can be created/destroyed */
class IContextObject {
public:
  IContextObject() = default;
  virtual ~IContextObject() = default;

  virtual void init() {};
  virtual void update() {}
  virtual void destroy() {};
};