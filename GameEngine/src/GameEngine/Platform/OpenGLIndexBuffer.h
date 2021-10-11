#include"GameEngine/IndexBuffer.h"
#include"GameEngine/Core.h"
namespace GameEngine {

	class HAZEL_API OpenGLIndexBuffer : public IndexBuffer
	{
	private:
		unsigned int m_RendererID;
	public:
		OpenGLIndexBuffer(int* indices, unsigned int size,int count);
		~OpenGLIndexBuffer();


		virtual void Bind() const;
		virtual void UnBind() const;

	};

}