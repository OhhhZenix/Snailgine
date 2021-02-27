#include "Input.hpp"

#if defined(SN_PLATFORM_WINDOW)
#include "Snailgine/Platform/Windows/WindowsInput.hpp"
#endif

namespace sn
{
	Input* Input::s_Instance = nullptr;

	void Input::Init()
	{
		if (s_Instance != nullptr)
		{
			return;
		}
#if defined(SN_PLATFORM_WINDOW)
		s_Instance = new WindowsInput();
#endif
	}

	void Input::Shutdown()
	{
		delete s_Instance;
	}

	bool Input::IsKeyPressed(int p_KeyCode)
	{
		return s_Instance->IsKeyPressedImpl(p_KeyCode);
	}

	bool Input::IsMouseButtonPressed(int p_Button)
	{
		return s_Instance->IsMouseButtonPressedImpl(p_Button);
	}

	Vec2f Input::GetMousePosition()
	{
		return s_Instance->GetMousePositionImpl();
	}
}