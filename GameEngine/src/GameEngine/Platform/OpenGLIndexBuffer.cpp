
#include"OpenGLIndexBuffer.h"
#include<glad/glad.h>

namespace GameEngine
{
	OpenGLIndexBuffer::OpenGLIndexBuffer(int* indices, unsigned int size,int count)
	{
		glCreateBuffers(1, &m_RendererID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size,indices, GL_STATIC_DRAW);
	}

	OpenGLIndexBuffer::~OpenGLIndexBuffer()
	{
		glDeleteBuffers(1, &m_RendererID);
	}

	void OpenGLIndexBuffer::Bind()	const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER ,m_RendererID);
	}

	void OpenGLIndexBuffer::UnBind()	const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
}

