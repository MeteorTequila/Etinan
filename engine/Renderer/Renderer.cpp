#include "Debug/Macros.h"
#include "Renderer/Renderer.h"


namespace EtinanMesh
{
	Renderer::Renderer() 
	{
		InitContext();
	}

	void Renderer::InitContext() 
	{
		ETN_PRINT("Init Renderer Context!\n");
		InitGLFW();
		InitOpenGLContext();
	}

	void Renderer::InitGLFW()
	{
		ETN_PRINT("Init GLFW\n");

		if (!glfwInit()) {
			ETN_PRINT("Init GLFW failed!\n");
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		m_Window = glfwCreateWindow(1366, 768, "Etinan Mesh", nullptr, nullptr);

		glfwMakeContextCurrent(m_Window);

		glfwSwapInterval(1); // ´¹Ö±Í¬²½


	}

	void Renderer::InitOpenGLContext() 
	{
		ETN_PRINT("Init OpenGL context\n");
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

		printf(" - - - - - Hardware Support Info:\n");
		printf("platform : (%s)\n", glGetString(GL_VENDOR));
		printf("renderer : (%s)\n", glGetString(GL_RENDERER));
		printf("version : (%s)\n", glGetString(GL_VERSION));
	}

	void Renderer::Update() 
	{
		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}

	void Renderer::Clear()
	{
		glClearColor(0.2f, 0.4f, 0.8f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Renderer::Render()
	{
		ETN_PRINT("Renderer rendering\n");
	}


	 
}