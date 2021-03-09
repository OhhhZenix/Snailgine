#include "Snailgine/Layer/Layer.hpp"

namespace sn
{
    Layer::Layer()
    {
        m_Enabled = true;
    }

    void Layer::OnAttach()
    {

    }

    void Layer::OnDetach()
    {

    }

    void Layer::ProcessUpdate(float p_DeltaTime)
    {

    }

    void Layer::ProcessRender()
    {

    }

    bool Layer::IsEnabled() const
    {
        return m_Enabled;
    }

    void Layer::SetEnabled(bool p_Enabled)
    {
        m_Enabled = p_Enabled;
    }
}