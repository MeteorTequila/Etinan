#pragma once
#include <memory>
namespace EtinanMesh 
{
	class EngineUI
	{
	public:
		~EngineUI();
		
		
		static EngineUI* Create();

	private:
		static EngineUI* s_EngineUI;
		EngineUI();
		
	};

}