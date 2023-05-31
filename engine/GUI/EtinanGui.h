#pragma once
#include <memory>

#include "GLFW/glfw3.h"
namespace EtinanMesh 
{
	class EngineGUI
	{
	public:
		~EngineGUI();
		EngineGUI(GLFWwindow* window);
		void Render();

	private:
		
		void SetContext();
		void Begin();
		void End();
	private:
		// 自定义的界面
		void ShowDemoImGui();
		void ShowCustomGui();
		
	private:
		GLFWwindow *m_Window = nullptr;
		bool m_IsShowDemoGUI = false;
		
	};

}