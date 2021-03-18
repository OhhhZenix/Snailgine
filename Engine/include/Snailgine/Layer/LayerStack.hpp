#pragma once

#include <Snailgine/Layer/Layer.hpp>

namespace sn {

class LayerStack {
private:
	std::vector<Layer*> m_layers;
	uint32_t m_layer_insert_index;

public:
	LayerStack();

	~LayerStack();

	void push_layer(Layer* p_layer);

	void pop_layer(Layer* p_layer);

	void push_overlay(Layer* p_overlay);

	void pop_overlay(Layer* p_overlay);

	std::vector<Layer*>& get_layers();
};

} // namespace sn