#pragma once
#include"GameEngine/Core.h"
#include"Layer.h"

#include<vector>

namespace GameEngine
{
	class HAZEL_API LayerStack {
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

	private:
		std::vector<Layer*>m_Layers;
		std::vector<Layer*>::iterator it;




	};

}
