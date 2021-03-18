#pragma once

#include <Snailgine/PCH.hpp>

namespace sn {

template <typename T>
using BoxPtr = std::unique_ptr<T>;

template <typename T, typename... Args>
constexpr BoxPtr<T> create_box_ptr(Args&&... args) {
	return std::make_unique<T>(std::forward<Args>(args)...);
}

template <typename T>
using RefCountPtr = std::shared_ptr<T>;

template <typename T, typename... Args>
constexpr RefCountPtr<T> create_ref_count_ptr(Args&&... args) {
	return std::make_shared<T>(std::forward<Args>(args)...);
}

constexpr uint16_t bit(uint16_t x)
{
	return static_cast<uint16_t>(1u << x);
}

} // namespace sn