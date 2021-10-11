#include"VertexBuffer.h"
#include"Renderer.h"
#include"Core.h"


#if CROSS_PLATFORM 
#include"Platform/OpenGLVertexBuffer.h"
#include"Platform/OpenGLIndexBuffer.h"
#endif




namespace GameEngine {


	VertexBuffer* VertexBuffer::Create(float* vertices,unsigned int size)
	{
		switch (Renderer::getRenderAPI())
		{
			case Renderer_API::None:	HZ_CORE_ASSERT(false, " NO API");
			case Renderer_API::OpenGL:	return new OpenGLVertexBuffer(vertices, size);
		}
		HZ_CORE_ASSERT(false, "Unknown Rendering API");
		return nullptr;


	}
}