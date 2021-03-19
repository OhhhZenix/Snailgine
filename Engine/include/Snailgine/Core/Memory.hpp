#pragma once

#include <Snailgine/PCH.hpp>

namespace sn {

template <typename T>
using BoxPtr = std::unique_ptr<T>;

template <typename T, typename... TArgs>
BoxPtr<T> makeBoxPtr(TArgs&&... p_args) {
	return std::make_unique<T>(std::forward<TArgs>(p_args)...);
}

template <typename T>
using RefCountPtr = std::shared_ptr<T>;

template <typename T, typename... TArgs>
RefCountPtr<T> makeRefCountPtr(TArgs&&... p_args) {
	return std::make_shared<T>(std::forward<TArgs>(p_args)...);
}

} // namespace sn