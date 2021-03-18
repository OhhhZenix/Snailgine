#pragma once

#include <Snailgine/Core/Base.hpp>

extern sn::Application* sn::create_application();

int main(int argc, char** argv) {
	sn::Log::init();
	auto l_app = sn::create_application();
	l_app->run();
	delete l_app;
}