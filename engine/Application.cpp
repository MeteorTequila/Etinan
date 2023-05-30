#include "Application.h"

#include "EtinanEngine.h"
#include "GUI/EtinanGui.h"

namespace EtinanMesh 
{
	

	void Init()
	{
		EtinanEngine::CreateEngine();
		EngineUI::CreateGUI();
		
	}



	void Shutdown()
	{
		
	}
}