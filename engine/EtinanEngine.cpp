#include "EtinanEngine.h"
#include <iostream>



namespace EtinanMesh 
{
	EtinanEngine* EtinanEngine::s_EtinanEngine = nullptr;


	EtinanEngine * EtinanEngine::Create()
	{
		return new EtinanEngine();
	}

	EtinanEngine::EtinanEngine()
	{
		printf(" - - - - - Start Engine!\n");
		InitGLFW();
		InitOpenGL();
	}

	

	EtinanEngine::~EtinanEngine()
	{
		printf(" - - - - - Shutdown Engine!\n");
	}

	void EtinanEngine::InitGLFW()
	{
		printf(" - - - - - init GLFW!\n");

		if (!glfwInit())
		{
			printf(" x x x x x GLFW init failed!\n");
		}

		m_Window = glfwCreateWindow(1366, 768, "Etinan Mesh", nullptr, nullptr);
	}

	void EtinanEngine::InitOpenGL()
	{
		glfwMakeContextCurrent(m_Window);

		printf(" - - - - - Init OpenGL context!\n");
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

		printf(" - - - - - Hardware Support Info:\n");
		printf("platform : (%s)\n", glGetString(GL_VENDOR));
		printf("renderer : (%s)\n", glGetString(GL_RENDERER));
		printf("version : (%s)\n", glGetString(GL_VERSION));
	}


}


