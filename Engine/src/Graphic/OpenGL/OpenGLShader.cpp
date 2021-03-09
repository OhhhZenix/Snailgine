#include "Snailgine/Graphic/OpenGL/OpenGLShader.hpp"

#include <glad/glad.h>

namespace sn
{
    void CheckCompileErrors(uint32_t p_Shader, const std::string& p_Type)
    {
        int32_t f_Compiled;
        int32_t f_Size;
        if (p_Type == "PROGRAM")
        {
            glGetProgramiv(p_Shader,
                           GL_LINK_STATUS,
                           &f_Compiled);
            if (f_Compiled == GL_FALSE)
            {
                glGetProgramiv(p_Shader,
                               GL_INFO_LOG_LENGTH,
                               &f_Size);
                std::vector<GLchar> f_ErrorLog(f_Size);
                glGetShaderInfoLog(p_Shader,
                                   f_Size,
                                   &f_Size,
                                   &f_ErrorLog[0]);
                SN_LOG_ERROR("ERROR::SHADER_COMPILATION_ERROR of type: {}",
                             p_Type);
                SN_LOG_ERROR("{}",
                             f_ErrorLog[0]);
            }
        }
        else
        {
            glGetShaderiv(p_Shader,
                          GL_COMPILE_STATUS,
                          &f_Compiled);
            if (f_Compiled == GL_FALSE)
            {
                glGetShaderiv(p_Shader,
                              GL_INFO_LOG_LENGTH,
                              &f_Size);
                std::vector<GLchar> f_ErrorLog(f_Size);
                glGetShaderInfoLog(p_Shader,
                                   f_Size,
                                   &f_Size,
                                   &f_ErrorLog[0]);
                SN_LOG_ERROR("ERROR::SHADER_COMPILATION_ERROR of type: {}",
                             p_Type);
                SN_LOG_ERROR("{}",
                             f_ErrorLog[0]);
            }
        }
    }

    OpenGLShader::OpenGLShader(const std::string& p_VertexPath, const std::string& p_FragmentPath)
    {
        m_RendererID = 0;

        // Retrieve the vertex/fragment source code from filePath
        std::string f_VertexCode;
        std::string f_FragmentCode;
        std::ifstream f_VertexFile;
        std::ifstream f_FragmentFile;

        // Ensure ifstream objects can throw exceptions:
        f_VertexFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        f_FragmentFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        try
        {
            // Open files
            f_VertexFile.open(p_VertexPath);
            f_FragmentFile.open(p_FragmentPath);
            std::stringstream vShaderStream, fShaderStream;

            // Read file's buffer contents into streams
            vShaderStream << f_VertexFile.rdbuf();
            fShaderStream << f_FragmentFile.rdbuf();

            // Close file handlers
            f_VertexFile.close();
            f_FragmentFile.close();

            // Convert stream into string
            f_VertexCode = vShaderStream.str();
            f_FragmentCode = fShaderStream.str();
        }
        catch (std::ifstream::failure& e)
        {
            SN_LOG_ERROR("ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ");
        }
        const char*f_VertexSource = f_VertexCode.c_str();
        const char*f_FragmentSource = f_FragmentCode.c_str();

        // Vertex shader
        uint32_t f_Vertex = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(f_Vertex,
                       1,
                       &f_VertexSource,
                       nullptr);
        glCompileShader(f_Vertex);
        CheckCompileErrors(f_Vertex,
                           "VERTEX");

        // Fragment Shader
        uint32_t f_Fragment = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(f_Fragment,
                       1,
                       &f_FragmentSource,
                       nullptr);
        glCompileShader(f_Fragment);
        CheckCompileErrors(f_Fragment,
                           "FRAGMENT");

        // Shader Program
        m_RendererID = glCreateProgram();
        glAttachShader(m_RendererID,
                       f_Vertex);
        glAttachShader(m_RendererID,
                       f_Fragment);
        glLinkProgram(m_RendererID);
        CheckCompileErrors(m_RendererID,
                           "PROGRAM");

        // Delete the shaders as they're linked into our program now and no longer necessary
        glDeleteShader(f_Vertex);
        glDeleteShader(f_Fragment);
    }
}