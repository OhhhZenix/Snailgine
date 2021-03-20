#pragma once

#include <Snailgine/Base.hpp>

namespace sn {

class Application
{
public:
  Application();

  virtual ~Application();

  static RefCountPtr<Application *> &instance();

  void run();
};

// To be defined by client
extern sn::Application *createApplication();

}// namespace sn