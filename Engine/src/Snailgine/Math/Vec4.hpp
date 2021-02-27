#pragma once

#include "Snailgine/Core/Base.hpp"

#define SQR(a) ((a) * (a))

#define DISTANCE_FROM_ORIGIN(a, b, c, d) sqrt(SQR(a) + SQR(b) + SQR(c) + SQR(d))

namespace sn
{
	template<typename T, typename DataType>
	class Vec4
	{
	 protected:
		__m128 m_Value;

		explicit Vec4(DataType f_Scalar)
		{
			m_Value = _mm_set_ps(f_Scalar, f_Scalar, f_Scalar, f_Scalar);
		}

		Vec4(DataType p_X, DataType p_Y, DataType p_Z, DataType p_W)
		{
			m_Value = _mm_set_ps(p_W, p_Z, p_Y, p_X);
		}

		Vec4(const Vec4& p_Vec)
		{
			m_Value = p_Vec.m_Value;
		}

		inline virtual T Normalized()
		{
			float f_Distance = DISTANCE_FROM_ORIGIN(this->operator[](0), this->operator[](1), this->operator[](2), this
				->operator[](3));
			return T(
				this->operator[](0) / f_Distance,
				this->operator[](1) / f_Distance, this->operator[](2) / f_Distance, this->operator[](3) / f_Distance);
		}

		inline virtual T& Add(const T& p_Other)
		{
			m_Value = _mm_add_ps(this->m_Value, p_Other.m_Value);
			return static_cast<T&>(*this);
		}

		inline virtual T& Subtract(const T& p_Other)
		{
			m_Value = _mm_sub_ps(this->m_Value, p_Other.m_Value);
			return static_cast<T&>(*this);
		}

		inline virtual T& Multiply(const T& p_Other)
		{
			m_Value = _mm_mul_ps(this->m_Value, p_Other.m_Value);
			return static_cast<T&>(*this);
		}

		inline virtual T& Divide(const T& p_Other)
		{
			m_Value = _mm_div_ps(this->m_Value, p_Other.m_Value);
			return static_cast<T&>(*this);
		}

		inline virtual T operator+(const T& p_Other)
		{
			return T(this->Add(p_Other));
		}

		inline virtual T operator-(const T& p_Other)
		{
			return T(this->Subtract(p_Other));
		}

		inline virtual T operator*(const T& p_Other)
		{
			return T(this->Multiply(p_Other));
		}

		inline virtual T operator/(const T& p_Other)
		{
			return T(this->Divide(p_Other));
		}

		inline virtual T& operator+=(const T& p_Right)
		{
			return this->Add(p_Right);
		}

		inline virtual T& operator-=(const T& p_Right)
		{
			return this->Subtract(p_Right);
		}

		inline virtual T& operator*=(const T& p_Right)
		{
			return this->Multiply(p_Right);
		}

		inline virtual T& operator/=(const T& p_Right)
		{
			return this->Divide(p_Right);
		}

		inline virtual Vec4& operator=(const __m128& p_Other)
		{
			m_Value = p_Other;
			return *this;
		}

		virtual DataType operator[](size_t p_Index) = 0;
	};

	class Vec4f : public Vec4<Vec4f, float>
	{
	 public:
		explicit Vec4f(float f_Scalar) : Vec4(f_Scalar)
		{

		}

		Vec4f(float p_X, float p_Y, float p_Z, float p_W)
			: Vec4(p_X, p_Y, p_Z, p_W)
		{

		}

		inline float operator[](size_t p_Index) override
		{
			return m_Value.m128_f32[p_Index];
		}
	};
}