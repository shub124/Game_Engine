#include"IndexBuffer.h"
#include"Renderer.h"
#include"Core.h"


#if CROSS_PLATFORM 
#include"Platform/OpenGLVertexBuffer.h"
#include"Platform/OpenGLIndexBuffer.h"
#endif




namespace GameEngine {


	IndexBuffer* IndexBuffer::Create(int* indices, unsigned int size,int count)
	{
		switch (Renderer::getRenderAPI())
		{
		case Renderer_API::None:	HZ_CORE_ASSERT(false, " NO API");
		case Renderer_API::OpenGL:	return new OpenGLIndexBuffer(indices, size,count);
		}
		HZ_CORE_ASSERT(false, "Unknown Rendering API");
		return nullptr;


	}
}