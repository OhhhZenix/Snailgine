
#include "BufferLayout.hpp"

namespace sn
{
	BufferLayout::BufferLayout()
	{
		m_Stride = 0;
	}

	BufferLayout::BufferLayout(std::initializer_list<BufferElement> p_Elements)
	{
		m_Stride = 0;
		m_Elements = p_Elements;
		CalculateOffsetsAndStride();
	}

	uint32_t BufferLayout::GetStride() const
	{
		return m_Stride;
	}

	const std::vector<BufferElement>& BufferLayout::GetElements() const
	{
		return m_Elements;
	}

	std::vector<BufferElement>::iterator BufferLayout::Begin()
	{
		return m_Elements.begin();
	}

	std::vector<BufferElement>::iterator BufferLayout::End()
	{
		return m_Elements.end();
	}

	std::vector<BufferElement>::const_iterator BufferLayout::Begin() const
	{
		return m_Elements.begin();
	}

	std::vector<BufferElement>::const_iterator BufferLayout::End() const
	{
		return m_Elements.end();
	}

	void BufferLayout::CalculateOffsetsAndStride()
	{
		size_t f_Offset = 0;
		m_Stride = 0;
		for (auto& f_Element : m_Elements)
		{
			f_Element.Offset = f_Offset;
			f_Offset += f_Element.Size;
			m_Stride += f_Element.Size;
		}
	}
}