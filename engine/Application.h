#pragma once
#include <memory>

#include "Renderer/Renderer.h"
#include "GUI/EtinanGUI.h"

namespace EtinanMesh
{
	class Application 
	{
	public:
		Application();
		~Application();

		void Run();
	private:
		
		std::unique_ptr<Renderer> m_Renderer;
		std::unique_ptr<EngineGUI> m_GUI;
		
	private:
		static Application* s_AppInstance; 
	};

	Application* CreateApplication();
	
}