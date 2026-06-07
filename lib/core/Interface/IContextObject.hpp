#pragma once

/* Object that can be created/destroyed */
class IContextObject {
public:
  IContextObject() = default;
  virtual ~IContextObject() = default;

  void init() {
    m_isAlive = true;
    onInit();
  };
  void update() {
    onUpdate();
  }
  void destroy() {
    onDestroy();
    m_isAlive = false;
  };

  bool isAlive() const {
    return m_isAlive;
  }

protected:
  virtual void onInit() {}
  virtual void onUpdate() {}
  virtual void onDestroy() {}

private:
  bool m_isAlive = false;
};