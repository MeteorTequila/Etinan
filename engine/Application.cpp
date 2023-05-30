#include "Application.h"

namespace EtinanMesh 
{
	static EtinanEngine* s_EngineRuntime = nullptr;

	EtinanEngine* Create()
	{
		s_EngineRuntime = new EtinanEngine();
		return s_EngineRuntime;
	}

	void Run() 
	{

	}

	void Shutdown()
	{
		delete  s_EngineRuntime;
	}
}