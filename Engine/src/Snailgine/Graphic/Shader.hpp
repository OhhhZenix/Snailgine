#pragma once

#include <glm/glm.hpp>
#include "Snailgine/PCH.hpp"

namespace sn
{
	class Shader
	{
	 public:
		static Shader* Create(const std::string& p_FilePath);

		static Shader* Create(const std::string& p_Name, const std::string& p_VertexSource, const std::string& p_FragmentSource);

		virtual ~Shader() = default;

		virtual void Bind() const = 0;

		virtual void Unbind() const = 0;

		virtual void SetInt(const std::string& p_Name, int p_Value) = 0;

		virtual void SetIntArray(const std::string& p_Name, int* p_Values, uint32_t p_Count) = 0;

		virtual void SetFloat(const std::string& p_Name, float p_Value) = 0;

		virtual void SetFloat2(const std::string& p_Name, const glm::vec2& p_Value) = 0;

		virtual void SetFloat3(const std::string& p_Name, const glm::vec3& p_Value) = 0;

		virtual void SetFloat4(const std::string& p_Name, const glm::vec4& p_Value) = 0;

		virtual void SetMat4(const std::string& p_Name, const glm::mat4& p_Value) = 0;

		[[nodiscard]] virtual const std::string& GetName() const = 0;
	};
}