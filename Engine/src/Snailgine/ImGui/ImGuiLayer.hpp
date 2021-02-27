#pragma once

#include "Snailgine/Layer/Layer.hpp"

namespace sn
{
	class ImGuiLayer : public Layer
	{
	 public:
		~ImGuiLayer() override = default;

		void OnAttach() override;

		void OnDetach() override;

		void ProcessRender() override;

		void Begin();

		void End();
	};
}