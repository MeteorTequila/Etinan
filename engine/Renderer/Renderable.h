#pragma once
#include <memory>
#include "IOmgr/Model.h"
#include "IOmgr/Shader.h"
#include "Renderer/ArrayAndBuffer.h"

namespace EtinanMesh 
{

	
	

	class Renderable 
	{
	public:
		~Renderable();
		Renderable();
	private:
		

	public:
		std::shared_ptr<Model> m_Model;
		std::shared_ptr<Shader> m_Shader;
		std::shared_ptr<VertexArray>m_VertexArray;
		std::shared_ptr<VertexBuffer>m_VertexBuffer;
		std::shared_ptr<IndexBuffer>m_IndexBuffer;
	};
}