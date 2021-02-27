#include "ImGuiLayer.hpp"

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <GLFW/glfw3.h>
#include "Snailgine/Core/Application.hpp"

namespace sn
{
	void ImGuiLayer::OnAttach()
	{
		// Setup Dear ImGui context
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& f_IO = ImGui::GetIO();
		(void)f_IO;
		f_IO.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
		//io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
		//f_IO.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
		//f_IO.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows
		//io.ConfigFlags |= ImGuiConfigFlags_ViewportsNoTaskBarIcons;
		//io.ConfigFlags |= ImGuiConfigFlags_ViewportsNoMerge;

		// Setup Dear ImGui style
		ImGui::StyleColorsDark();
		//ImGui::StyleColorsClassic();

		// When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
		ImGuiStyle& f_Style = ImGui::GetStyle();
		if (f_IO.ConfigFlags /*& ImGuiConfigFlags_ViewportsEnable*/)
		{
			f_Style.WindowRounding = 0.0f;
			f_Style.Colors[ImGuiCol_WindowBg].w = 1.0f;
		}

		Application& f_App = Application::Instance();
		auto* window = static_cast<GLFWwindow*>(f_App.GetWindow().GetHandle());

		// Setup Platform/Renderer bindings
		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui_ImplOpenGL3_Init("#version 410");
	}

	void ImGuiLayer::OnDetach()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}

	void ImGuiLayer::ProcessRender()
	{
		static bool f_Show = true;
		ImGui::ShowDemoWindow(&f_Show);
	}

	void ImGuiLayer::Begin()
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}

	void ImGuiLayer::End()
	{
		ImGuiIO& f_IO = ImGui::GetIO();
		Application& f_App = Application::Instance();
		f_IO.DisplaySize = ImVec2(f_App.GetWindow().GetWidth(), f_App.GetWindow().GetHeight());

		// Rendering
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		if (f_IO.ConfigFlags /*& ImGuiConfigFlags_ViewportsEnable*/)
		{
			GLFWwindow* f_BackupCurrentContext = glfwGetCurrentContext();
			// ImGui::UpdatePlatformWindows();
			// ImGui::RenderPlatformWindowsDefault();
			glfwMakeContextCurrent(f_BackupCurrentContext);
		}
	}
}