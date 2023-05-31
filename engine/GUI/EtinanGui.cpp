#include "Debug/Macros.h"
#include "EtinanGui.h"

#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends//imgui_impl_opengl3.h"


namespace EtinanMesh
{


	EngineGUI::~EngineGUI() 
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}

	EngineGUI::EngineGUI(GLFWwindow* window):m_Window(window)
	{
		ETN_PRINT(" - - - - - Create GUI!\n");
		SetContext();
		m_IsShowDemoGUI = true;
		
		
	}

	void EngineGUI::Render()
	{
		Begin();
		ShowDemoImGui();

		ShowCustomGui();
		End();
		
	}

	void EngineGUI::SetContext() 
	{
		// Setup Dear ImGui context
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // Enable Docking
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;       // Enable Multi-Viewport / Platform Windows

		// Setup Dear ImGui style
		ImGui::StyleColorsDark();
		//ImGui::StyleColorsLight();
		ImGuiStyle& style = ImGui::GetStyle();
		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			style.WindowRounding = 0.0f;
			style.Colors[ImGuiCol_WindowBg].w = 1.0f;
		}

		// Setup Platform/Renderer backends
		ImGui_ImplGlfw_InitForOpenGL(m_Window, true);
		ImGui_ImplOpenGL3_Init("#version 330");
	}

	void EngineGUI::Begin()
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}

	void EngineGUI::End()
	{
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			GLFWwindow* backup_current_context = glfwGetCurrentContext();
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
			glfwMakeContextCurrent(backup_current_context);
		}
	}

	void EngineGUI::ShowDemoImGui()
	{

		ImGui::ShowDemoWindow(&m_IsShowDemoGUI);

	}

	// - - - - - - - - - - - - - - - - - - - - - - - - 
	// - - - - - - - - 自定义GUI界面  - - - - - - - - - 
	// - - - - - - - - - - - - - - - - - - - - - - - - 

	void EngineGUI::ShowCustomGui()
	{

		ImGui::Begin("Hello, world!");
		ImGui::Text("This is some useful text.");
		if (ImGui::Button("Button")) {
			m_GUICounter++;
		}
		ImGui::Text("counter = %d", m_GUICounter);
		ImGui::End();
	}

	

}