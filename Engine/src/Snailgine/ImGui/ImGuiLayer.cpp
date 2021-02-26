#include "ImGuiLayer.hpp"

#include "Snailgine/Core/Application.hpp"

namespace sn
{

	void ImGuiLayer::OnAttach()
	{
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& f_IO = ImGui::GetIO();
		f_IO.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		f_IO.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		ImVec4 a;

		// Setup Platform/Renderer bindings
		ImGui_ImplGlfw_InitForOpenGL(static_cast<GLFWwindow*>(Application::Instance().GetWindow().GetHandle()), true);
		ImGui_ImplOpenGL3_Init("#version 410");
	}

	void ImGuiLayer::OnDetach()
	{
		Layer::OnDetach();
	}

	void ImGuiLayer::ProcessUpdate(float p_DeltaTime)
	{
		ImGuiIO& f_IO = ImGui::GetIO();
		f_IO.DeltaTime = p_DeltaTime;
		f_IO.DisplaySize = ImVec2(Application::Instance().GetWindow().GetWidth(), Application::Instance().GetWindow().GetHeight());

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		static bool f_Show = true;
		ImGui::ShowDemoWindow(&f_Show);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}
}