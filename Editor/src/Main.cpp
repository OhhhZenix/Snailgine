#include <Snailgine.hpp>

class Sandbox : public sn::Application {
public:
	Sandbox() {
	}

	~Sandbox() override {}
};

sn::Application* sn::createApplication() {
	return new Sandbox();
}