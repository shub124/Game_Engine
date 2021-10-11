#include"GameEngine/VertexBuffer.h"
#include"GameEngine/Core.h"
namespace GameEngine {

	class HAZEL_API OpenGLVertexBuffer : public VertexBuffer
	{
	private:
		unsigned int m_RendererID;
	public:
		OpenGLVertexBuffer(float* vertices, unsigned int size);
		~OpenGLVertexBuffer();
		

		virtual void Bind() const;
		virtual void UnBind() const;
		
	};

}