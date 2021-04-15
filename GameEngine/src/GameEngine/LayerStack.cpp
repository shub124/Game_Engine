#include"LayerStack.h"

namespace GameEngine {

	LayerStack::LayerStack()
	{
		it = m_Layers.begin();
	}

	LayerStack::~LayerStack()
	{
		for (Layer* layer : m_Layers)
		{
			delete layer;

		}
	}

	void LayerStack::PushLayer(Layer* layer)
	{
		it = m_Layers.emplace(it,layer);
	}

	void LayerStack::PopLayer(Layer* layer)
	{
		auto iterator = std::find(m_Layers.begin(), m_Layers.end(), layer);
		if (iterator != m_Layers.end())
		{
			m_Layers.erase(iterator);
			it--;
		}
	}

	void LayerStack::PushOverlay(Layer* layer)
	{
		m_Layers.emplace_back(layer);
	}

	void LayerStack::PopOverlay(Layer* overlay)
	{
		auto iterator = std::find(m_Layers.begin(),m_Layers.end(), overlay);
		if (iterator != m_Layers.end())
		{
			m_Layers.erase(iterator);
		}
	}
}