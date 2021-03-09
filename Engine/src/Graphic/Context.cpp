#include "Snailgine/Graphic/Context.hpp"

#include "Snailgine/Core/Log.hpp"
#include "Snailgine/Graphic/Renderer.hpp"
#include "Snailgine/Graphic/OpenGL/OpenGLContext.hpp"

namespace sn
{
    Context*Context::Create(void*p_Window)
    {
        switch (Renderer::GetAPI())
        {
            case GraphicAPI::OpenGL:
                return new OpenGLContext(p_Window);
            case GraphicAPI::Vulkan:
            case GraphicAPI::None:
                break;
        }

        SN_LOG_ASSERT(false,
                      "Unknown/Unimplemented graphics api!");
        return nullptr;
    }
}