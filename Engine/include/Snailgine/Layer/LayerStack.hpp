#pragma once

#include "Snailgine/Core/Base.hpp"
#include "Snailgine/Layer/Layer.hpp"

namespace sn
{
    class LayerStack
    {
        private:
            std::vector<Layer*> m_Layers;
            uint32_t m_LayerInsertIndex;

        public:
            LayerStack();

            ~LayerStack();

            void PushLayer(Layer*p_Layer);

            void PopLayer(Layer*p_Layer);

            void PushOverlay(Layer*p_Overlay);

            void PopOverlay(Layer*p_Overlay);

            std::vector<Layer*>& GetLayers();
    };
}