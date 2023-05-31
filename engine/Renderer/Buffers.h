#pragma
#include "glad/glad.h"
#include "glfw/glfw3.h"
namespace EtinanMesh 
{
	class VertexBuffer
	{
	public:
		VertexBuffer(float *vertices, uint32_t size)
		{
			glGenBuffers(1, &m_ID);
			Bind();
			glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
		}
		inline void Bind() { glBindBuffer(GL_ARRAY_BUFFER, m_ID); }
		inline void UnBind() { glBindBuffer(GL_ARRAY_BUFFER, 0); }
	private:
		unsigned int m_ID;
	};

	class IndexBuffer
	{
	public:
		IndexBuffer(uint32_t *indices, uint32_t count)
		{
			glGenBuffers(1, &m_ID);
			Bind();
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(uint32_t), indices, GL_STATIC_DRAW);
		}
		inline void Bind() { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID); }
		inline void UnBind() { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }
	private:
		unsigned int m_ID;
	};
}