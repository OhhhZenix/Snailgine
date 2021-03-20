#include "Snailgine/Core/Application.hpp"

namespace sn {

static RefCountPtr<Application *> s_instance = nullptr;

Application::Application()
{
  SN_LOG_ASSERT(!s_instance, "Application instance already exists!")
  s_instance = makeRefCountPtr<Application *>(this);
}

Application::~Application(){
  SN_LOG_INFO("Deconstructed")
}

RefCountPtr<Application *> &Application::instance()
{
  return s_instance;
}

void Application::run() {}

}// namespace sn