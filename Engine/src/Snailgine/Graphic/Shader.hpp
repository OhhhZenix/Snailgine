#pragma once

#include "Snailgine/PCH.hpp"

namespace sn
{
	enum class ShaderDataType
	{
		None,
		Float, Float2, Float3, Float4,
		Mat3, Mat4,
		Int, Int2, Int3, Int4,
		Bool
	};

	uint32_t GetShaderSizeByType(ShaderDataType p_Type);
}