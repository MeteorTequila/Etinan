#pragma once
#include <string>
#include <vector>
#include "glm/glm.hpp"
namespace EtinanMesh 
{
	class Model
	{
	public:
		Model(const std::string &fileName);
		~Model()=default;

	private:
		void LoadMeshFromFile(const std::string &fileName);
	private:
		std::vector<glm::vec3> m_Positons;
		std::vector<glm::vec3> m_Normals;
		std::vector<glm::vec2> m_TexCoords;
	};

}