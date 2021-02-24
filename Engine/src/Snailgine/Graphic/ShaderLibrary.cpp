#include "ShaderLibrary.hpp"

namespace sn
{
	ShaderLibrary::~ShaderLibrary()
	{
		if (!m_Shaders.empty())
		{
			for (auto& [f_Name, f_Shader] : m_Shaders) {
				delete f_Shader;
			}
		}
	}

	void ShaderLibrary::Add(const std::string& p_Name, Shader* p_Shader)
	{
		m_Shaders[p_Name] = p_Shader;
	}

	void ShaderLibrary::Add(Shader* p_Shader)
	{
		auto& f_Name = p_Shader->GetName();
		Add(f_Name, p_Shader);
	}

	Shader* ShaderLibrary::Load(const std::string& filepath)
	{
		auto shader = Shader::Create(filepath);
		Add(shader);
		return shader;
	}

	Shader* ShaderLibrary::Load(const std::string& p_Name, const std::string& filepath)
	{
		auto shader = Shader::Create(filepath);
		Add(p_Name, shader);
		return shader;
	}

	Shader* ShaderLibrary::Get(const std::string& p_Name)
	{
		return m_Shaders[p_Name];
	}

	bool ShaderLibrary::Exists(const std::string& p_Name) const
	{
		return m_Shaders.find(p_Name) != m_Shaders.end();
	}
}