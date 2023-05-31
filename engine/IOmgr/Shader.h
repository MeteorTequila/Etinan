#pragma once
#include <string>
#include "GLFW/glfw3.h"
#include "glad/glad.h"

#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"

namespace EtinanMesh {
	class Shader
	{
	public:
		Shader() = default;
		Shader(const std::string &vsPath, const std::string&fsPath, const std::string &gsPath = nullptr);
	public:
		void Bind();
		void UnBind();

		// uniform¹¤¾ßº¯Êý
		void setBool(const std::string &name, bool value) const;
		void setInt(const std::string &name, int value) const;
		void setFloat(const std::string &name, float value) const;
		void setFloat2(const std::string &name, const glm::vec2 &vec) const;
		void setFloat2(const std::string &name, float x, float y) const;
		void setFloat3(const std::string &name, const glm::vec3 &vec) const;
		void setFloat3(const std::string &name, float x, float y, float z) const;
		void setFloat4(const std::string &name, const glm::vec4 &vec) const;
		void setFloat4(const std::string &name, float x, float y, float z, float w) const;
		void setMat4(const std::string &name, const glm::mat4 &mat) const;

	private:
		std::string ReadFromFile(const std::string &filePath);
		void Compile(const std::string &vsCode, const std::string &fsCode, const std::string &gsCode = nullptr);
		void CheckCompileError(unsigned int shader, std::string type);
	private:
		unsigned int m_ShaderID;
		
	};

}