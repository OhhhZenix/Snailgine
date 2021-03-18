#include "Snailgine/Layer/Layer.hpp"

namespace sn {

Layer::Layer() {
	m_enabled = true;
}

void Layer::on_attach() {}

void Layer::on_detach() {}

void Layer::process_render() {}

void Layer::process_update(float p_delta_time) {}

bool Layer::is_enabled() const {
	return m_enabled;
}

void Layer::set_enabled(bool p_enabled) {
	m_enabled = p_enabled;
}

} // namespace sn