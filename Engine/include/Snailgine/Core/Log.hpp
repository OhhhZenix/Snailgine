#pragma once

#include <spdlog/fmt/ostr.h>
#include <spdlog/spdlog.h>
#include <Snailgine/Core/Base.hpp>

namespace sn {

class Log {
private:
	static RefCountPtr<spdlog::logger> s_logger;

public:
	static void init();

	static RefCountPtr<spdlog::logger>& get_logger();
};

} // namespace sn

// Logging only works in debug builds
#if defined(SN_BUILD_DEBUG)
#define SN_LOG_TRACE(...) \
	{ ::sn::Log::get_logger()->trace(__VA_ARGS__); }
#define SN_LOG_DEBUG(...) \
	{ ::sn::Log::get_logger()->debug(__VA_ARGS__); }
#define SN_LOG_INFO(...) \
	{ ::sn::Log::get_logger()->info(__VA_ARGS__); }
#define SN_LOG_WARN(...) \
	{ ::sn::Log::get_logger()->warn(__VA_ARGS__); }
#define SN_LOG_ERROR(...) \
	{ ::sn::Log::get_logger()->error(__VA_ARGS__); }
#define SN_LOG_CRITICAL(...) \
	{ ::sn::Log::get_logger()->critical(__VA_ARGS__); }
#define SN_LOG_ASSERT(x, ...)                \
	{                                        \
		if (!(x)) {                          \
			SN_LOG_ERROR("{0}", __VA_ARGS__) \
			assert(false);                   \
		}                                    \
	}
#else
#define SN_LOG_TRACE(...)
#define SN_LOG_DEBUG(...)
#define SN_LOG_INFO(...)
#define SN_LOG_WARN(...)
#define SN_LOG_ERROR(...)
#define SN_LOG_CRITICAL(...)
#define SN_LOG_ASSERT(x, ...)
#endif