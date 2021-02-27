#pragma once

namespace sn {
	template<typename T, typename DataType>
	class Vec2
	{
	 protected:
		__m128 m_Value;

		explicit Vec2(DataType f_Scalar)
		{
			m_Value = _mm_set_ps(static_cast<DataType>(0), static_cast<DataType>(0), f_Scalar, f_Scalar);
		}

		Vec2(DataType p_X, DataType p_Y)
		{
			m_Value = _mm_set_ps(static_cast<DataType>(0), static_cast<DataType>(0), p_Y, p_X);
		}

		Vec2(const Vec2& p_Vec)
		{
			m_Value = p_Vec.m_Value;
		}

		inline virtual T Normalized()
		{
			return T(0);
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

		inline virtual Vec2& operator=(const __m128& p_Other)
		{
			m_Value = p_Other;
			return *this;
		}

		virtual DataType operator[](size_t p_Index) = 0;
	};

	class Vec2f : public Vec2<Vec2f, float>
	{
	 public:
		explicit Vec2f(float f_Scalar) : Vec2(f_Scalar)
		{

		}

		Vec2f(float p_X, float p_Y)
			: Vec2(p_X, p_Y)
		{

		}

		inline float operator[](size_t p_Index) override
		{
			return m_Value.m128_f32[p_Index];
		}
	};
}