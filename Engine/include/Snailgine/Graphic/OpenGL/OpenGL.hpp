#pragma once

#include "Snailgine/Graphic/Graphic.hpp"

namespace sn
{
    class OpenGL : public Graphic
    {
        public:
            void Init() override;

            void SetViewport(uint32_t p_X, uint32_t p_Y, uint32_t p_Width, uint32_t p_Height) override;

            void SetClearColor(float p_R, float p_G, float p_B, float p_A) override;

            void Clear() override;
    };
}