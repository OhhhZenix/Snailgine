#pragma once

#include "Snailgine/PCH.hpp"
#include "Snailgine/Debug/Instrumentor.hpp"

namespace sn
{
    template<typename T>
    using RcPtr = std::shared_ptr<T>;

    template<typename T, typename ... Args>
    constexpr RcPtr<T> MakeRcPtr(Args&& ... args)
    {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }

    template<typename T>
    using BoxPtr = std::unique_ptr<T>;

    template<typename T, typename ... Args>
    constexpr BoxPtr<T> MakeBoxPtr(Args&& ... args)
    {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }

    constexpr uint16_t Bit(uint16_t x)
    {
        return static_cast<uint16_t>(1u << x);
    }
}