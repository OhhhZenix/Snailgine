#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#include "Snailgine/Core/Base.hpp"

namespace sn
{
	class Log
	{
	 private:
		std::shared_ptr<spdlog::logger> m_Logger;

	 private:
		// some data
		Log();

	 public:
		static void Init();

		static Log& Instance();

		std::shared_ptr<spdlog::logger>& GetLogger();

	 public:
		// Copy construct
		Log(Log const&) = delete;

		// Move construct
		Log(Log&&) = delete;

		// Copy assign
		Log& operator=(Log const&) = delete;

		// Move assign
		Log& operator=(Log&&) = delete;
	};
}

// Logging only works in debug builds
#if defined(SN_BUILD_DEBUG)
#define SN_LOG_TRACE(...)      ::sn::Log::Instance().GetLogger()->trace(__VA_ARGS__)
#define SN_LOG_DEBUG(...)      ::sn::Log::Instance().GetLogger()->debug(__VA_ARGS__)
#define SN_LOG_INFO(...)       ::sn::Log::Instance().GetLogger()->info(__VA_ARGS__)
#define SN_LOG_WARN(...)       ::sn::Log::Instance().GetLogger()->warn(__VA_ARGS__)
#define SN_LOG_ERROR(...)      ::sn::Log::Instance().GetLogger()->error(__VA_ARGS__)
#define SN_LOG_CRITICAL(...)   ::sn::Log::Instance().GetLogger()->critical(__VA_ARGS__)
#define SN_LOG_ASSERT(x, ...) { if (!(x)) { SN_LOG_ERROR("assertion failed reason={0}", __VA_ARGS__); assert(false); } }
#else
#define SN_LOG_TRACE(...)
#define SN_LOG_DEBUG(...)
#define SN_LOG_INFO(...)
#define SN_LOG_WARN(...)
#define SN_LOG_ERROR(...)
#define SN_LOG_CRITICAL(...)
#define SN_LOG_ASSERT(x, ...)
#endif