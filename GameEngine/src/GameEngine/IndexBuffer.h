#pragma once
#include<glad/glad.h>
#include "Core.h"
namespace GameEngine {

	class HAZEL_API	IndexBuffer
	{
	public:
		virtual ~IndexBuffer() {}

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;
		static IndexBuffer* Create(int* indices, unsigned int size,int count);


	};
}


