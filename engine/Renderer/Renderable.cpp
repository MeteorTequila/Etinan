#include "Debug/Macros.h"
#include "Renderer/Renderable.h"



namespace EtinanMesh 
{
	Renderable::~Renderable()
	{
		m_VertexArray.reset();
		m_VertexBuffer.reset();
		m_IndexBuffer.reset();
	}

	Renderable::Renderable() 
	{
		m_Model = std::make_shared<Model>("../assets/stanford_bunny.obj");

		float vertices[] = {
		-0.5f, -0.5f, 0.0f, // left  
		 0.5f, -0.5f, 0.0f, // right 
		 0.0f,  0.5f, 0.0f  // top   
		};

		m_VertexArray = std::make_shared<VertexArray>();
		m_VertexBuffer = std::make_shared<VertexBuffer>(vertices,sizeof(vertices));
		//m_IndexBuffer = std::make_shared<IndexBuffer>();
	}

	
	
}