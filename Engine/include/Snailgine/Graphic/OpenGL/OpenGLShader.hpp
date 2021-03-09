#pragma once

#include "Snailgine/Graphic/Shader.hpp"

namespace sn
{
    class OpenGLShader : public Shader
    {
        private:
            uint32_t m_RendererID;

        public:
            OpenGLShader(const std::string& p_VertexPath, const std::string& p_FragmentPath);

            void Bind() const override;

            void Unbind() const override;

            void SetInt(const std::string& p_Name, int32_t p_Value) override;

            void SetIntArray(const std::string& p_Name, int32_t*p_Values, uint32_t p_Count) override;

            void SetFloat(const std::string& p_Name, float p_Value) override;

            void SetFloat2(const std::string& p_Name, const Vec2f& p_Value) override;

            void SetFloat3(const std::string& p_Name, const Vec3f& p_Value) override;

            void SetFloat4(const std::string& p_Name, const Vec4f& p_Value) override;

            void SetMat4(const std::string& p_Name, const Mat4& p_Value) override;
    };
}