#pragma once

/* Object that can be created/destroyed */
class IContextObject {
public:
  IContextObject() = default;
  virtual ~IContextObject() = default;

  virtual void pollEvents() = 0;
  virtual void destroy() = 0;
};