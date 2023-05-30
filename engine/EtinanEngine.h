#pragma once
#include<memory>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
namespace EtinanMesh 
{
	class EtinanEngine
	{
	public:
		
		~EtinanEngine();
		static void CreateEngine();
		inline static EtinanEngine& GetEngineInstance() {return *s_EtinanEngine; }
		inline GLFWwindow* GetWindow() { return m_Window; }
		void Run();



	private:
		static std::unique_ptr<EtinanEngine>s_EtinanEngine;
		EtinanEngine();
		
	private:
		// GLFW
		GLFWwindow * m_Window;
		int m_Width, m_Height;
		void InitGLFW();

		// OpenGL by Glad
		void InitOpenGL();

	};
}

