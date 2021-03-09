#pragma once

#include "Snailgine/Core/Base.hpp"
#include "Snailgine/Math/Vec2.hpp"
#include "Snailgine/Math/Vec3.hpp"
#include "Snailgine/Math/Vec4.hpp"
#include "Snailgine/Math/Mat4.hpp"

namespace sn
{
    class Shader
    {
        public:
            static Shader*Create(const std::string& p_VertexPath, const std::string& p_FragmentPath);

            virtual ~Shader() = default;

            virtual void Bind() const = 0;

            virtual void Unbind() const = 0;

            virtual void SetInt(const std::string& p_Name, int32_t p_Value) = 0;

            virtual void SetIntArray(const std::string& p_Name, int32_t*p_Values, uint32_t p_Count) = 0;

            virtual void SetFloat(const std::string& p_Name, float p_Value) = 0;

            virtual void SetFloat2(const std::string& p_Name, const Vec2f& p_Value) = 0;

            virtual void SetFloat3(const std::string& p_Name, const Vec3f& p_Value) = 0;

            virtual void SetFloat4(const std::string& p_Name, const Vec4f& p_Value) = 0;

            virtual void SetMat4(const std::string& p_Name, const Mat4& p_Value) = 0;
    };
}