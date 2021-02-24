#pragma once

#include "Snailgine/Graphic/Shader.hpp"

namespace sn
{
	class ShaderLibrary
	{
	 private:
		std::unordered_map<std::string, Shader*> m_Shaders;

	 public:
		~ShaderLibrary();

		void Add(const std::string& p_Name, Shader* p_Shader);

		void Add(Shader* p_Shader);

		Shader* Load(const std::string& filepath);

		Shader* Load(const std::string& p_Name, const std::string& filepath);

		Shader* Get(const std::string& p_Name);

		[[nodiscard]] bool Exists(const std::string& p_Name) const;
	};
}