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
		
		
		// �Զ������
	
		// �������
	public:
		int m_GUICounter = 0;
	private:
		// ���沼��
		void ShowDemoImGui();
		void ShowCustomGui();
	};

}