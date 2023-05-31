#include "Debug/Macros.h"
#include "IOmgr/Model.h"
namespace EtinanMesh 
{
	Model::Model(const std::string &fileName)
	{
		LoadMeshFromFile(fileName);

	}

	void Model::LoadMeshFromFile(const std::string &fileName)
	{
		
	}
}