#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"
namespace EtinanMesh
{
	class Renderer
	{
	public:
		Renderer();
		~Renderer() = default;
		inline GLFWwindow * GetWindow() { return m_Window; }
		inline bool ShouldClose() { return glfwWindowShouldClose(m_Window); }
		void Clear();
		void Update();
		void Render();
	private:
		void InitContext();
	private:
		void InitGLFW();
		void InitOpenGLContext();

	private:
		GLFWwindow * m_Window;

	};

	
}