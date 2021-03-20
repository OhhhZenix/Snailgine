#pragma once

#include <spdlog/fmt/ostr.h>
#include <spdlog/spdlog.h>

#include <Snailgine/Core/Memory.hpp>

namespace sn::Log {

void init();

RefCountPtr<spdlog::logger> &getLogger();

}// namespace sn::Log

// Logging only works in debug builds
#if defined(SN_BUILD_DEBUG)
#define SN_LOG_TRACE(...) ::sn::Log::getLogger()->trace(__VA_ARGS__);
#define SN_LOG_DEBUG(...) ::sn::Log::getLogger()->debug(__VA_ARGS__);
#define SN_LOG_INFO(...) ::sn::Log::getLogger()->info(__VA_ARGS__);
#define SN_LOG_WARN(...) ::sn::Log::getLogger()->warn(__VA_ARGS__);
#define SN_LOG_ERROR(...) ::sn::Log::getLogger()->error(__VA_ARGS__);
#define SN_LOG_CRITICAL(...) ::sn::Log::getLogger()->critical(__VA_ARGS__);
#define SN_LOG_ASSERT(x, ...)                                   \
  {                                                             \
    if (!(x)) {                                                 \
      SN_LOG_ERROR("assertion failed reason={0}", __VA_ARGS__); \
      assert(false);                                            \
    }                                                           \
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