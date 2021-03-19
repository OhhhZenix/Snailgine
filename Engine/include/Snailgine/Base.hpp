#pragma once

#include <Snailgine/Core/Log.hpp>

namespace sn {

constexpr uint16_t bit(uint16_t p_x) {
	return static_cast<uint16_t>(1u << p_x);
}

} // namespace sn