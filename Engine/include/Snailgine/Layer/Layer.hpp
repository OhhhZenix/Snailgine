#pragma once

namespace sn {

class Layer {
private:
	bool m_enabled;

public:
	Layer();

	virtual ~Layer() = default;

	virtual void on_attach();

	virtual void on_detach();

	virtual void process_render();

	virtual void process_update(float p_delta_time);

	bool is_enabled() const;

	void set_enabled(bool p_enabled);
};

} // namespace sn