#pragma once
#include"Core.h"




namespace GameEngine {
	class HAZEL_API Renderer {
	private:
	 static Renderer_API s_renderer;
	public:
		inline static  Renderer_API getRenderAPI()
		{
			return s_renderer;
		}

		inline void setRendererAPI(Renderer_API value)
		{
			
			s_renderer=value;
		}

		


	};
}

