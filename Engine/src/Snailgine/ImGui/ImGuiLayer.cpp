#include "ImGuiLayer.hpp"

#include <imgui_impl_opengl3.h>
#include <GLFW/glfw3.h>
#include "Snailgine/Core/Application.hpp"
#include "Snailgine/Event/EventBus.hpp"

namespace sn
{

	void ImGuiLayer::OnAttach()
	{
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& f_IO = ImGui::GetIO();
		f_IO.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		f_IO.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		f_IO.KeyMap[ImGuiKey_Tab] = GLFW_KEY_TAB;
		f_IO.KeyMap[ImGuiKey_LeftArrow] = GLFW_KEY_LEFT;
		f_IO.KeyMap[ImGuiKey_RightArrow] = GLFW_KEY_RIGHT;
		f_IO.KeyMap[ImGuiKey_UpArrow] = GLFW_KEY_UP;
		f_IO.KeyMap[ImGuiKey_DownArrow] = GLFW_KEY_DOWN;
		f_IO.KeyMap[ImGuiKey_PageUp] = GLFW_KEY_PAGE_UP;
		f_IO.KeyMap[ImGuiKey_PageDown] = GLFW_KEY_PAGE_DOWN;
		f_IO.KeyMap[ImGuiKey_Home] = GLFW_KEY_HOME;
		f_IO.KeyMap[ImGuiKey_End] = GLFW_KEY_END;
		f_IO.KeyMap[ImGuiKey_Insert] = GLFW_KEY_INSERT;
		f_IO.KeyMap[ImGuiKey_Delete] = GLFW_KEY_DELETE;
		f_IO.KeyMap[ImGuiKey_Backspace] = GLFW_KEY_BACKSPACE;
		f_IO.KeyMap[ImGuiKey_Space] = GLFW_KEY_SPACE;
		f_IO.KeyMap[ImGuiKey_Enter] = GLFW_KEY_ENTER;
		f_IO.KeyMap[ImGuiKey_Escape] = GLFW_KEY_ESCAPE;
		f_IO.KeyMap[ImGuiKey_A] = GLFW_KEY_A;
		f_IO.KeyMap[ImGuiKey_C] = GLFW_KEY_C;
		f_IO.KeyMap[ImGuiKey_V] = GLFW_KEY_V;
		f_IO.KeyMap[ImGuiKey_X] = GLFW_KEY_X;
		f_IO.KeyMap[ImGuiKey_Y] = GLFW_KEY_Y;
		f_IO.KeyMap[ImGuiKey_Z] = GLFW_KEY_Z;

		// Setup Platform/Renderer bindings
		// ImGui_ImplGlfw_InitForOpenGL(static_cast<GLFWwindow*>(Application::Instance().GetWindow().GetHandle()), true);
		ImGui_ImplOpenGL3_Init("#version 410");

		EventBus::Instance().Subscribe(this, &ImGuiLayer::OnMouseButtonPressedEvent);
		EventBus::Instance().Subscribe(this, &ImGuiLayer::OnMouseButtonReleasedEvent);
		EventBus::Instance().Subscribe(this, &ImGuiLayer::OnMouseMovedEvent);
		EventBus::Instance().Subscribe(this, &ImGuiLayer::OnMouseScrolledEvent);
		EventBus::Instance().Subscribe(this, &ImGuiLayer::OnKeyPressedEvent);
		EventBus::Instance().Subscribe(this, &ImGuiLayer::OnKeyReleasedEvent);
		EventBus::Instance().Subscribe(this, &ImGuiLayer::OnKeyTypedEvent);
		EventBus::Instance().Subscribe(this, &ImGuiLayer::OnWindowResizeEvent);
	}

	void ImGuiLayer::OnDetach()
	{
		Layer::OnDetach();
	}

	void ImGuiLayer::ProcessUpdate(float p_DeltaTime)
	{
		ImGuiIO& f_IO = ImGui::GetIO();
		f_IO.DisplaySize = ImVec2(Application::Instance().GetWindow().GetWidth(), Application::Instance().GetWindow().GetHeight());
		f_IO.DeltaTime = p_DeltaTime;

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		static bool f_Show = true;
		ImGui::ShowDemoWindow(&f_Show);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void ImGuiLayer::OnMouseButtonPressedEvent(MouseButtonPressedEvent& p_Event)
	{
		SN_LOG_INFO("PRESSED {}", p_Event.GetButton());
		ImGuiIO f_IO = ImGui::GetIO();
		SN_LOG_INFO("IMGUI PRSSED {}", f_IO.MouseDown[static_cast<int>(p_Event.GetButton())]);
		f_IO.MouseDown[static_cast<int>(p_Event.GetButton())] = true;
		SN_LOG_INFO("IMGUI PRSSED {}", f_IO.MouseDown[static_cast<int>(p_Event.GetButton())]);
	}

	void ImGuiLayer::OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& p_Event)
	{
		ImGuiIO f_IO = ImGui::GetIO();
		f_IO.MouseDown[static_cast<int>(p_Event.GetButton())] = false;
	}

	void ImGuiLayer::OnMouseMovedEvent(MouseMovedEvent& p_Event)
	{
		SN_LOG_INFO("{} {}", p_Event.GetX(), p_Event.GetY());
		ImGuiIO f_IO = ImGui::GetIO();
		f_IO.MousePos = ImVec2(p_Event.GetX(), p_Event.GetY());
	}

	void ImGuiLayer::OnMouseScrolledEvent(MouseScrolledEvent& p_Event)
	{
		ImGuiIO f_IO = ImGui::GetIO();
		f_IO.MouseWheelH += p_Event.GetXOffset();
		f_IO.MouseWheel += p_Event.GetYOffset();
	}

	void ImGuiLayer::OnKeyPressedEvent(KeyPressedEvent& p_Event)
	{

	}

	void ImGuiLayer::OnKeyReleasedEvent(KeyReleasedEvent& p_Event)
	{

	}

	void ImGuiLayer::OnKeyTypedEvent(KeyTypedEvent& p_Event)
	{

	}

	void ImGuiLayer::OnWindowResizeEvent(WindowResizeEvent& p_Event)
	{
		ImGuiIO f_IO = ImGui::GetIO();
		f_IO.DisplaySize = ImVec2(p_Event.GetWidth(), p_Event.GetHeight());
		f_IO.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
	}
}