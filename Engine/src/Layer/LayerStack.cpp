#include "Snailgine/Layer/LayerStack.hpp"

namespace sn
{
    LayerStack::LayerStack()
    {
        m_LayerInsertIndex = 0;
    }

    LayerStack::~LayerStack()
    {
        if (!m_Layers.empty())
        {
            for (Layer*f_Layer : m_Layers)
            {
                f_Layer->OnDetach();
                delete f_Layer;
            }
            m_Layers.clear();
        }
    }

    void LayerStack::PushLayer(Layer*p_Layer)
    {
        m_Layers.emplace(m_Layers.begin() + m_LayerInsertIndex,
                         p_Layer);
        m_LayerInsertIndex++;
    }

    void LayerStack::PopLayer(Layer*p_Layer)
    {
        auto f_Iterator = std::find(m_Layers.begin(),
                                    m_Layers.end(),
                                    p_Layer);
        if (f_Iterator != m_Layers.end())
        {
            m_Layers.erase(f_Iterator);
            m_LayerInsertIndex--;
        }
    }

    void LayerStack::PushOverlay(Layer*p_Overlay)
    {
        m_Layers.emplace_back(p_Overlay);
    }

    void LayerStack::PopOverlay(Layer*p_Overlay)
    {
        auto f_Iterator = std::find(m_Layers.begin(),
                                    m_Layers.end(),
                                    p_Overlay);
        if (f_Iterator != m_Layers.end())
        {
            m_Layers.erase(f_Iterator);
        }
    }

    std::vector<Layer*>& LayerStack::GetLayers()
    {
        return m_Layers;
    }
}