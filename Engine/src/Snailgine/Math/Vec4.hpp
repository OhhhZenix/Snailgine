#pragma once

#include "Snailgine/Core/Base.hpp"

#define SQR(a) ((a) * (a))

#define DISTANCE_FROM_ORIGIN(a, b, c, d) sqrt(SQR(a) + SQR(b) + SQR(c) + SQR(d))

namespace sn
{
	class Vec4f
	{
	 private:
		__m128 m_Value{};

	 public:
		Vec4f(float p_X, float p_Y, float p_Z, float p_W)
		{
			m_Value = _mm_set_ps(p_W, p_Z, p_Y, p_X);
		}

		Vec4f(const Vec4f& p_Vec) {
			m_Value = p_Vec.m_Value;
		}

		inline Vec4f& operator=(const __m128& p_Other)
		{
			m_Value = p_Other;
			return *this;
		}

		inline float operator[](size_t p_Index)
		{
			return m_Value.m128_f32[p_Index];
		}

		inline Vec4f& Add(const Vec4f& p_Other) {
			m_Value = _mm_add_ps(this->m_Value, p_Other.m_Value);
			return *this;
		}

		inline Vec4f& Subtract(const Vec4f& p_Other) {
			m_Value = _mm_sub_ps(this->m_Value, p_Other.m_Value);
			return *this;
		}

		inline Vec4f& Multiply(const Vec4f& p_Other) {
			m_Value = _mm_mul_ps(this->m_Value, p_Other.m_Value);
			return *this;
		}

		inline Vec4f& Divide(const Vec4f& p_Other) {
			m_Value = _mm_div_ps(this->m_Value, p_Other.m_Value);
			return *this;
		}

		inline Vec4f operator+(const Vec4f& p_Other) {
			return Vec4f(this->Add(p_Other));
		}

		inline Vec4f operator-(const Vec4f& p_Other) {
			return Vec4f(this->Subtract(p_Other));
		}

		inline Vec4f operator*(const Vec4f& p_Other) {
			return Vec4f(this->Multiply(p_Other));
		}

		inline Vec4f operator/(const Vec4f& p_Other) {
			return Vec4f(this->Divide(p_Other));
		}

		inline Vec4f& operator+=(const Vec4f& p_Right) {
			return this->Add(p_Right);
		}

		inline Vec4f& operator-=(const Vec4f& p_Right) {
			return this->Subtract(p_Right);
		}

		inline Vec4f& operator*=(const Vec4f& p_Right) {
			return this->Multiply(p_Right);
		}

		inline Vec4f& operator/=(const Vec4f& p_Right) {
			return this->Divide(p_Right);
		}

		inline Vec4f Normalized()
		{
			float f_Distance = DISTANCE_FROM_ORIGIN(this->operator[](0), this->operator[](1), this->operator[](2), this->operator[](3));
			return Vec4f(this->operator[](0) / f_Distance, this->operator[](1) / f_Distance, this->operator[](2) / f_Distance, this->operator[](3) / f_Distance);
		}
	};
}