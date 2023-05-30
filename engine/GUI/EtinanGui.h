#pragma once
#include <memory>

#include "GLFW/glfw3.h"
namespace EtinanMesh 
{
	class EngineUI
	{
	public:
		~EngineUI();
		
		 static void CreateGUI();

	private:
		EngineUI();
		void SetContext();
		void Begin();
		void End();
		void ShowDemoImGui();
		
	private:
		GLFWwindow *m_Window = nullptr;
		static std::unique_ptr<EngineUI> s_EngineUI;
		bool m_IsShowDemoImGui = false;
		
	};

}