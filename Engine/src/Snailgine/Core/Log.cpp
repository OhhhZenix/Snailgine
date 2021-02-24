#include "Log.hpp"

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace sn
{
	Log::Log()
	{
		std::vector<spdlog::sink_ptr> f_LogSinks;
		f_LogSinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
		f_LogSinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("Snailgine.log", true));

		f_LogSinks[0]->set_pattern("%^[%T] %n: %v%$");
		f_LogSinks[1]->set_pattern("[%T] [%l] %n: %v");

		m_Logger = MakeRcPtr<spdlog::logger>("Snailgine", begin(f_LogSinks), end(f_LogSinks));
		m_Logger->set_level(spdlog::level::trace);
		m_Logger->flush_on(spdlog::level::trace);
		spdlog::register_logger(m_Logger);
	}

	void Log::Init()
	{
		// By calling Instance function it creates the instance of the log
		// Essentially initializing the logger in a way
		Instance();
	}

	Log& Log::Instance()
	{
		static Log s_Instance;
		return s_Instance;
	}

	RcPtr<spdlog::logger>& Log::GetLogger()
	{
		return m_Logger;
	}
}