#include "Debug/Macros.h"
#include "Application.h"


#include "GUI/EtinanGui.h"

namespace EtinanMesh 
{
	Application* Application::s_AppInstance = nullptr;

	Application* CreateApplication()
	{
		return new Application();
	}

	Application::Application()
	{
		if (s_AppInstance) 
		{
			ETN_PRINT("Application already exists!");
		}
		s_AppInstance = this;

		// 初始化Renderer
		m_Renderer.reset(new Renderer);
		// 初始化GUI
		m_GUI.reset(new EngineGUI(m_Renderer->GetWindow()));
	}

	Application::~Application()
	{
		delete s_AppInstance;
	}

	void Application::Run() 
	{
		while (!m_Renderer->ShouldClose()) 
		{
			m_Renderer->Clear();

			m_GUI->Render();
			m_Renderer->Render();
			m_Renderer->Update();
		}
		//m_Renderer->Run();
	}

}