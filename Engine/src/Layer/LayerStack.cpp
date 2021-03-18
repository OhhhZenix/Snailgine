#include "Snailgine/Layer/LayerStack.hpp"

namespace sn {

LayerStack::LayerStack() {
	m_layer_insert_index = 0;
}

LayerStack::~LayerStack() {
	if (!m_layers.empty()) {
		for (Layer* l_layer : m_layers) {
			l_layer->on_detach();
			delete l_layer;
		}
		m_layers.clear();
	}
}

void LayerStack::push_layer(Layer* p_layer) {
	m_layers.emplace(m_layers.begin() + m_layer_insert_index, p_layer);
	m_layer_insert_index++;
}

void LayerStack::pop_layer(Layer* p_layer) {
	auto l_iterator = std::find(m_layers.begin(), m_layers.end(), p_layer);
	if (l_iterator != m_layers.end()) {
		m_layers.erase(l_iterator);
		m_layer_insert_index--;
	}
}

void LayerStack::push_overlay(Layer* p_overlay) {
	m_layers.emplace_back(p_overlay);
}

void LayerStack::pop_overlay(Layer* p_overlay) {
	auto l_iterator = std::find(m_layers.begin(), m_layers.end(), p_overlay);
	if (l_iterator != m_layers.end()) {
		m_layers.erase(l_iterator);
	}
}

std::vector<Layer*>& LayerStack::get_layers() {
	return m_layers;
}

} // namespace sn