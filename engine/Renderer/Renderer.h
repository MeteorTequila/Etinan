#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Renderer/Renderable.h"
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
		void PrepareToRender();
	private:
		// context
		void InitGLFW();
		void InitOpenGLContext();
		void BindCallbacks();

	private:
		GLFWwindow * m_Window;
		std::shared_ptr<Renderable> m_Renderable;
	};

	
}