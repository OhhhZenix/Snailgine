#pragma once

namespace sn
{
	class Layer
	{
	 private:
		bool m_Enabled;

	 public:
		Layer();

		virtual ~Layer() = default;

		virtual void OnAttach();

		virtual void OnDetach();

		virtual void ProcessUpdate(float p_DeltaTime);

		virtual void ProcessRender();

		[[nodiscard]] bool IsEnabled() const;

		void SetEnabled(bool p_Enabled);
	};
}