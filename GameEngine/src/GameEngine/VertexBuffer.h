#pragma once
#include<glad/glad.h>
#include"Core.h"
namespace GameEngine {

	class HAZEL_API VertexBuffer
	{
	public:
		virtual ~VertexBuffer() {}

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;
		static VertexBuffer* Create(float* vertices, unsigned int size);
		
		
	};
}


