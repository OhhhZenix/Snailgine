#include "BufferElement.hpp"

namespace sn
{
	BufferElement::BufferElement()
	{
		Type = ShaderDataType::None;
		Name = "";
		Normalized = false;
		Offset = 0;
		Size = 0;
	}

	BufferElement::BufferElement(ShaderDataType p_Type, const std::string& p_Name, bool p_Normalized)
	{
		Type = p_Type;
		Name = p_Name;
		Normalized = p_Normalized;
		Offset = 0;
		Size = 0;
	}

	uint32_t BufferElement::GetComponentCount() const
	{
		switch (Type)
		{
		case ShaderDataType::Float:
			return 1;
		case ShaderDataType::Float2:
			return 2;
		case ShaderDataType::Float3:
			return 3;
		case ShaderDataType::Float4:
			return 4;
		case ShaderDataType::Mat3:
			return 3; // 3* float3
		case ShaderDataType::Mat4:
			return 4; // 4* float4
		case ShaderDataType::Int:
			return 1;
		case ShaderDataType::Int2:
			return 2;
		case ShaderDataType::Int3:
			return 3;
		case ShaderDataType::Int4:
			return 4;
		case ShaderDataType::Bool:
			return 1;
		case ShaderDataType::None:
			break;
		}
		return 0;
	}
}