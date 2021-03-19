#include "Snailgine/Core/Log.hpp"

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace sn::Log {

static RefCountPtr<spdlog::logger> s_logger = nullptr;

void init() {
	if (s_logger) {
		SN_LOG_ASSERT(false, "Logger already initialized!")
		return;
	}
	std::vector<spdlog::sink_ptr> f_logSinks;
	f_logSinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
	f_logSinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("Snailgine.log", true));

	f_logSinks[0]->set_pattern("%^[%T] %n: %v%$");
	f_logSinks[1]->set_pattern("[%T] [%l] %n: %v");

	s_logger = makeRefCountPtr<spdlog::logger>("Snailgine", begin(f_logSinks), end(f_logSinks));
	s_logger->set_level(spdlog::level::trace);
	s_logger->flush_on(spdlog::level::trace);
	spdlog::register_logger(s_logger);
}

RefCountPtr<spdlog::logger>& getLogger() {
	SN_LOG_ASSERT(s_logger, "Logger not initialized yet!")
	return s_logger;
}

} // namespace sn::Log