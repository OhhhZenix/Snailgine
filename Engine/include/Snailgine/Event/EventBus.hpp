#pragma once

#include <Snailgine/Event/Event.hpp>

#define SN_BIND_EVENT(p_type, p_function) EventBus::subscribe<p_type>(std::bind(p_function, this, std::placeholders::_1));

namespace sn {

class IEventCallback {
public:
	virtual ~IEventCallback() = default;

	virtual void execute(const Event& p_event) = 0;
};

template <typename T>
using EventFunctionPtr = std::function<void(const T&)>;

template <typename T>
class EventCallback : public IEventCallback {
private:
	EventFunctionPtr<T> m_function;

public:
	EventCallback(EventFunctionPtr<T> p_function) {
		m_function = p_function;
	}

	void execute(const Event& p_event) override {
		m_function(*(T*)&p_event);
	}
};

class EventBus {
public:
	using FunctionList = std::vector<IEventCallback*>;

private:
	static std::unordered_map<std::type_index, FunctionList> s_subscribers;

public:
	static void init();

	static void shutdown();

	template <typename T>
	static void subscribe(EventFunctionPtr<T> p_function) {
		s_subscribers[typeid(T)].push_back(new EventCallback<T>(p_function));
	}

	template <typename T>
	static void publish(const T& p_event) {
		FunctionList& f_functions = s_subscribers[typeid(T)];
		if (f_functions.empty()) {
			return;
		}

		std::thread l_thread([&f_functions, &p_event]() {
			for (auto& f_function : f_functions) {
				if (f_function == nullptr) {
					continue;
				}
				f_function->execute(p_event);
			}
		});

		if (l_thread.joinable()) {
			l_thread.join();
		}
	}
};

} // namespace sn