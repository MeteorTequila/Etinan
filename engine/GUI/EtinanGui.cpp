#include "EtinanGui.h"

namespace EtinanMesh
{
	EngineUI* EngineUI::s_EngineUI = nullptr;

	EngineUI* EngineUI::Create()
	{
		s_EngineUI= new EngineUI();
		return s_EngineUI;
	}

	EngineUI::~EngineUI() 
	{
		delete s_EngineUI;
	}

	EngineUI::EngineUI()
	{
		printf(" - - - - - Create GUI!\n");
	}

}