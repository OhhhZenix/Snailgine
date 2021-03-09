#pragma once

#include "Snailgine/Graphic/RenderCommand.hpp"

namespace sn
{
    class Renderer
    {
        public:
            static void Init();

            static void Shutdown();

            static GraphicAPI GetAPI();
    };
}