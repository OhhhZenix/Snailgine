#include <imgui.h>
#include <Snailgine.hpp>

class ExampleLayer : public sn::Layer
{
 public:
	void ProcessRender() override {
		ImGui::Begin("Test");
		ImGui::Text("Hello World!");
		ImGui::End();
	}
};

int main()
{
	// Snailgine Initialize
	sn::Init();

	// Some setups

	sn::Application::Instance().PushLayer(new ExampleLayer());

	// Runs the app;
	sn::Application::Instance().Run();
}