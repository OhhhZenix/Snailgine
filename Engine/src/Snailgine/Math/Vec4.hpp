#pragma once

#include "Snailgine/Core/Base.hpp"

namespace sn
{
	template<typename T, typename DataType>
	class Vec4
	{
	 protected:
		__m128 m_Value;

	 public:
		explicit Vec4(DataType p_X = static_cast<DataType>(0), DataType p_Y = static_cast<DataType>(0), DataType p_Z = static_cast<DataType>(0), DataType p_W = static_cast<DataType>(0))
		{
			m_Value = _mm_set_ps(p_X, p_Y, p_Z, p_W);
		}

		inline T& operator=(const __m128& p_Other)
		{
			m_Value = p_Other;
			return *this;
		}

		inline explicit operator __m128() const
		{
			return m_Value;
		}

		virtual DataType operator[](size_t p_Index) = 0;

		inline T operator+(const T& p_Other)
		{
			return _mm_add_ps(&this, p_Other);
		}

		inline T operator-(const T& p_Other)
		{
			return _mm_sub_ps(&this, p_Other);
		}

		inline T operator*(const T& p_Other)
		{
			return _mm_mul_ps(&this, p_Other);
		}

		inline T operator/(const T& p_Other)
		{
			return _mm_div_ps(&this, p_Other);
		}
	};

	class Vec4f : public Vec4<Vec4f, float>
	{
	 public:
		float operator[](size_t p_Index) override
		{
			return m_Value.m128_f32[p_Index];
		}
	};

	class Vec4i : public Vec4<Vec4i, uint32_t>
	{
	 public:
		explicit Vec4i(uint32_t p_X = 0, uint32_t p_Y = 0, uint32_t p_Z = 0, uint32_t p_W = 0)
			: Vec4<Vec4i, uint32_t>(p_X, p_Y, p_Z, p_W)
		{
		}

		uint32_t operator[](size_t p_Index) override
		{
			return m_Value.m128_f32[p_Index];
		}
	};
}