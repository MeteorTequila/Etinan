#include "Debug/Macros.h"
#include "IOmgr/Shader.h"

#include <fstream>
#include <iostream>
#include <sstream>
namespace EtinanMesh
{
	Shader::Shader(const std::string &vsPath, const std::string&fsPath, const std::string &gsPath)
	{
		// 读取文件
		std::string vertexSource, fragmentSource, geometrySource;
		vertexSource = ReadFromFile(vsPath);
		fragmentSource = ReadFromFile(fsPath);
		if (&gsPath!=nullptr)
		{
			geometrySource = ReadFromFile(gsPath);
		}

		// 编译shader
		Compile(vertexSource, fragmentSource, &gsPath == nullptr ? nullptr : geometrySource);
	}

	std::string Shader::ReadFromFile(const std::string &filePath)
	{
		std::string sourceCode;
		std::ifstream file;
		file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

		try {
			file.open(filePath);
			std::stringstream fileStream;
			fileStream << file.rdbuf();
			file.close();
			sourceCode = fileStream.str();
		}
		catch (std::ifstream::failure& e)
		{
			std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ: " << e.what() << std::endl;
			return NULL;
		}
		return sourceCode;
	}

	void Shader::Compile(const std::string &vSource, const std::string &fSource, const std::string &gSource)
	{
		const GLchar *vCode = (const GLchar *)vSource.c_str();
		const GLchar *fCode = (const GLchar *)fSource.c_str();
		const GLchar *gCode = (const GLchar *)gSource.c_str();

		unsigned int vertexShader, fragmentShader, geometryShader;

		// 创建 vertex shader
		vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vCode, NULL);
		glCompileShader(vertexShader);
		CheckCompileError(vertexShader, "VERTEX");

		// 创建 fragment shader
		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fCode, NULL);
		glCompileShader(fragmentShader);
		CheckCompileError(fragmentShader, "FRAGMENT");

		// 创建 geometry shader
		if (gCode) {
			geometryShader = glCreateShader(GL_GEOMETRY_SHADER);
			glShaderSource(geometryShader, 1, &gCode, NULL);
			glCompileShader(geometryShader);
			CheckCompileError(fragmentShader, "GEOMETRY");
		}

		// 链接shader program
		m_ShaderID = glCreateProgram();

		glAttachShader(m_ShaderID, vertexShader);
		glAttachShader(m_ShaderID, fragmentShader);
		if (gCode)
		{
			glAttachShader(m_ShaderID, geometryShader);
		}

		glLinkProgram(m_ShaderID);
		CheckCompileError(m_ShaderID, "PROGRAM");


		// 释放资源
		glDeleteProgram(m_ShaderID);
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
		glDeleteShader(geometryShader);

	}

	void Shader::CheckCompileError(unsigned int shader, std::string type)
	{
		int success;
		char infoLog[1024];
		if (type != "PROGRAM")
		{
			glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
			if (!success)
			{
				glGetShaderInfoLog(shader, 1024, NULL, infoLog);
				std::cout
					<< "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n"
					<< infoLog
					<< "\n -- --------------------------------------------------- -- "
					<< std::endl;
			}
		}
		else
		{
			glGetProgramiv(shader, GL_LINK_STATUS, &success);
			if (!success)
			{
				glGetProgramInfoLog(shader, 1024, NULL, infoLog);
				std::cout
					<< "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n"
					<< infoLog
					<< "\n -- --------------------------------------------------- -- "
					<< std::endl;
			}
		}
	}


	void Shader::Bind() 
	{
		glUseProgram(m_ShaderID);
	}

	void Shader::UnBind() 
	{
		glUseProgram(0);
	}

	void Shader::setBool(const std::string & name, bool value) const
	{
		GLint location = glGetUniformLocation(m_ShaderID, name.c_str());
		glUniform1i(location, (int)value);
	}

	void Shader::setInt(const std::string & name, int value) const
	{
		GLint location = glGetUniformLocation(m_ShaderID, name.c_str());
		glUniform1i(location, value);
	}

	void Shader::setFloat(const std::string & name, float value) const
	{
		GLint location = glGetUniformLocation(m_ShaderID, name.c_str());
		glUniform1f(location, value);
	}

	void Shader::setFloat2(const std::string & name, const glm::vec2 & vec) const
	{
		GLint location = glGetUniformLocation(m_ShaderID, name.c_str());
		glUniform2fv(location, 1, &vec[0]);
	}

	void Shader::setFloat2(const std::string & name, float x, float y) const
	{
		GLint location = glGetUniformLocation(m_ShaderID, name.c_str());
		glUniform2f(location, x, y);
	}

	void Shader::setFloat3(const std::string & name, const glm::vec3 & vec) const
	{
		GLint location = glGetUniformLocation(m_ShaderID, name.c_str());
		glUniform3fv(location, 1, &vec[0]);
	}

	void Shader::setFloat3(const std::string & name, float x, float y, float z) const
	{
		GLint location = glGetUniformLocation(m_ShaderID, name.c_str());
		glUniform3f(location, x, y, z);
	}

	void Shader::setFloat4(const std::string & name, const glm::vec4 & vec) const
	{
		GLint location = glGetUniformLocation(m_ShaderID, name.c_str());
		glUniform4fv(location, 1, &vec[0]);
	}

	void Shader::setFloat4(const std::string & name, float x, float y, float z, float w) const
	{
		GLint location = glGetUniformLocation(m_ShaderID, name.c_str());
		glUniform4f(location, x, y, z, w);
	}

	void Shader::setMat4(const std::string & name, const glm::mat4 & mat) const
	{
		GLint location = glGetUniformLocation(m_ShaderID, name.c_str());
		glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(mat));
	}
}