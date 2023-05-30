#include "EtinanEngine.h"
#include <iostream>



namespace EtinanMesh 
{
	std::unique_ptr<EtinanEngine> EtinanEngine::s_EtinanEngine = nullptr;


	void EtinanEngine::CreateEngine()
	{
		s_EtinanEngine.reset(new EtinanEngine);
	}


	EtinanEngine::EtinanEngine()
	{
		printf(" - - - - - Start Engine!\n");
		InitGLFW();
		InitOpenGL();
		//Run();
	}

	

	EtinanEngine::~EtinanEngine()
	{
		printf(" - - - - - Shutdown Engine!\n");
		s_EtinanEngine.reset();
	}

	void EtinanEngine::InitGLFW()
	{
		printf(" - - - - - init GLFW!\n");

		if (!glfwInit())
		{
			printf(" x x x x x GLFW init failed!\n");
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);


		m_Width = 1366;
		m_Height = 768;
		m_Window = glfwCreateWindow(1366, 768, "Etinan Mesh", nullptr, nullptr);
		if (m_Window == nullptr) 
		{
			printf(" x x x x x GLFW window create failed!\n");
		}

		glfwMakeContextCurrent(m_Window);
	}

	void EtinanEngine::InitOpenGL()
	{
		

		printf(" - - - - - Init OpenGL context!\n");
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

		printf(" - - - - - Hardware Support Info:\n");
		printf("platform : (%s)\n", glGetString(GL_VENDOR));
		printf("renderer : (%s)\n", glGetString(GL_RENDERER));
		printf("version : (%s)\n", glGetString(GL_VERSION));

	}

	void EtinanEngine::Run()
	{
		while (!glfwWindowShouldClose(m_Window)) 
		{
			glClearColor(0.2f, 0.4f, 0.8f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}
	}


}


