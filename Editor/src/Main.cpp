#include <Snailgine.hpp>

class App : public sn::Application {
public:
	App() {

	}

	~App() override {

	}
};

sn::Application* sn::create_application() {
	return new App();
}