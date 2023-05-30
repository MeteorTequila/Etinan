#include "Application.h"
#include <memory>

#include "EtinanEngine.h"
#include "GUI/EtinanGui.h"

namespace EtinanMesh 
{
	EtinanEngine *runtime = nullptr;
	EngineUI *GUI = nullptr;
	

	void Create()
	{
		runtime = EtinanEngine::Create();
		GUI = EngineUI::Create();
	}

	void Run() 
	{
		
	}

	void Shutdown()
	{
		
	}
}