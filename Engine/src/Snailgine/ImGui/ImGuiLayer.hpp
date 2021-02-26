#pragma once

#include <imgui_impl_opengl3.h>
#include <imgui_impl_glfw.h>
#include "Snailgine/Layer/Layer.hpp"

namespace sn {
	class ImGuiLayer : public Layer
	{
	 public:
		~ImGuiLayer() override = default;

		void OnAttach() override;

		void OnDetach() override;

		void ProcessUpdate(float p_DeltaTime) override;


	};
}