#pragma once
#include "glad/glad.h"
#include "GLFW/glfw3.h"
namespace EtinanMesh 
{
	class EtinanEngine
	{
	public:
		static EtinanEngine* Create();
		~EtinanEngine();
	private:
		EtinanEngine();
	private:
		static EtinanEngine* s_EtinanEngine;
	private:
		// GLFW
		GLFWwindow * m_Window;
		void InitGLFW();

		// OpenGL by Glad
		void InitOpenGL();

	};
}

