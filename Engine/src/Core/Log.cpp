#include "Snailgine/Core/Log.hpp"

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace sn {

static bool s_log_init = false;
RefCountPtr<spdlog::logger> Log::s_logger;

void Log::init() {
	if (s_log_init) {
		SN_LOG_ASSERT(false, "Log already initialized")
		return;
	}

	std::vector<spdlog::sink_ptr> f_log_sinks;
	f_log_sinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
	f_log_sinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("Snailgine.log", true));

	f_log_sinks[0]->set_pattern("%^[%T] %n: %v%$");
	f_log_sinks[1]->set_pattern("[%T] [%l] %n: %v");

	s_logger = create_ref_count_ptr<spdlog::logger>("Snailgine", begin(f_log_sinks), end(f_log_sinks));
	s_logger->set_level(spdlog::level::trace);
	s_logger->flush_on(spdlog::level::trace);
	spdlog::register_logger(s_logger);

    s_log_init = true;
}

RefCountPtr<spdlog::logger>& Log::get_logger() {
	return s_logger;
}

} // namespace sn