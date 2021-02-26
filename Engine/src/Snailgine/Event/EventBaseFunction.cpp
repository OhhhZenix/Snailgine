#include "EventBaseFunction.hpp"

namespace sn
{
	void EventBaseFunction::Execute(Event* p_Event)
	{
		Call(p_Event);
	}
}