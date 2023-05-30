#include "EtinanGui.h"

#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends//imgui_impl_opengl3.h"

#include "EtinanEngine.h"

namespace EtinanMesh
{

	std::unique_ptr<EngineUI> EngineUI::s_EngineUI = nullptr;

	void EngineUI::CreateGUI()
	{
		
		s_EngineUI.reset(new EngineUI);
	}

	EngineUI::~EngineUI() 
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();

		s_EngineUI.reset();
	}

	EngineUI::EngineUI()
	{
		printf(" - - - - - Create GUI!\n");
		SetContext();
		Begin();
		m_IsShowDemoImGui = true;
		ShowDemoImGui(); 
		End();
	}

	void EngineUI::SetContext() 
	{
		// Setup Dear ImGui context
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

		// Setup Dear ImGui style
		ImGui::StyleColorsDark();
		//ImGui::StyleColorsLight();

		// Setup Platform/Renderer backends
		EtinanEngine &app = EtinanEngine::GetEngineInstance();
		m_Window = app.GetWindow();

		ImGui_ImplGlfw_InitForOpenGL(m_Window, true);
		ImGui_ImplOpenGL3_Init("#version 330");

		// Our state
		bool show_demo_window = true;
		bool show_another_window = false;
		ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
	}

	void EngineUI::Begin()
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}

	void EngineUI::End()
	{
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void EngineUI::ShowDemoImGui()
	{
		ImGui::ShowDemoWindow(&m_IsShowDemoImGui);
	}

	

}