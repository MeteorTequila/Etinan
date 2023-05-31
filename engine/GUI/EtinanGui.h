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
		GLFWwindow *m_Window = nullptr;
		bool m_IsShowDemoGUI = false;
		
		
		// 自定义界面
	
		// 界面参数
	public:
		int m_GUICounter = 0;
	private:
		// 界面布局
		void ShowDemoImGui();
		void ShowCustomGui();
	};

}