#pragma once

#include <Snailgine/Base.hpp>

#if defined(SN_PLATFORM_WINDOW)

extern sn::Application* sn::createApplication();

int main(int argc, char** argv) {
	sn::Log::init();
	auto f_app = sn::createApplication();
	f_app->run();
	delete f_app;
}

#else
#error Platform not supported!
#endif