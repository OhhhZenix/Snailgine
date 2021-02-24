#pragma once

#include "Snailgine/Core/Log.hpp"

namespace sn
{
	using FloatingPointMicroseconds = std::chrono::duration<double, std::micro>;

	struct ProfileResult
	{
		std::string Name;

		FloatingPointMicroseconds Start;
		std::chrono::microseconds ElapsedTime;
		std::thread::id ThreadID;
	};

	struct InstrumentationSession
	{
		std::string Name;
	};

	class Instrumentor
	{
	 private:
		std::mutex m_Mutex;
		InstrumentationSession* m_CurrentSession;
		std::ofstream m_OutputStream;

	 private:
		Instrumentor();

		~Instrumentor();

	 public:
		static Instrumentor& Instance();

		void BeginSession(const std::string& p_Name, const std::string& p_FilePath = "results.json");

		void EndSession();

		void WriteProfile(const ProfileResult& p_Result);

	 private:
		void WriteHeader();

		void WriteFooter();

		// Note: you must already own lock on m_Mutex before
		// calling InternalEndSession()
		void InternalEndSession();

	 public:
		// Copy construct
		Instrumentor(Instrumentor const&) = delete;

		// Move construct
		Instrumentor(Instrumentor&&) = delete;

		// Copy assign
		Instrumentor& operator=(Instrumentor const&) = delete;

		// Move assign
		Instrumentor& operator=(Instrumentor&&) = delete;
	};

	class InstrumentationTimer
	{
	 private:
		const char* m_Name;
		bool m_Stopped;
		std::chrono::time_point<std::chrono::steady_clock> m_StartTimePoint;

	 public:
		InstrumentationTimer(const char* p_Name);

		~InstrumentationTimer();

		void Stop();
	};

	namespace InstrumentorUtils
	{
		template<size_t N>
		struct ChangeResult
		{
			char Data[N];
		};

		template<size_t N, size_t K>
		constexpr auto CleanupOutputString(const char(& p_Expr)[N], const char(& p_Remove)[K])
		{
			ChangeResult<N> result = {};

			size_t srcIndex = 0;
			size_t dstIndex = 0;
			while (srcIndex < N)
			{
				size_t matchIndex = 0;
				while (matchIndex < K - 1 && srcIndex + matchIndex < N - 1
					   && p_Expr[srcIndex + matchIndex] == p_Remove[matchIndex])
					matchIndex++;
				if (matchIndex == K - 1)
					srcIndex += matchIndex;
				result.Data[dstIndex++] = p_Expr[srcIndex] == '"' ? '\'' : p_Expr[srcIndex];
				srcIndex++;
			}
			return result;
		}
	}
}

#if defined(SN_PROFILE)

// Figure outs the function signature
#if defined(__GNUC__) || (defined(__MWERKS__) && (__MWERKS__ >= 0x3000)) || (defined(__ICC) && (__ICC >= 600)) || defined(__ghs__)
#define SN_FUNC_SIG __PRETTY_FUNCTION__
#elif defined(__DMC__) && (__DMC__ >= 0x810)
#define SN_FUNC_SIG __PRETTY_FUNCTION__
#elif (defined(__FUNCSIG__) || (_MSC_VER))
#define SN_FUNC_SIG __FUNCSIG__
#elif (defined(__INTEL_COMPILER) && (__INTEL_COMPILER >= 600)) || (defined(__IBMCPP__) && (__IBMCPP__ >= 500))
#define SN_FUNC_SIG __FUNCTION__
#elif defined(__BORLANDC__) && (__BORLANDC__ >= 0x550)
#define SN_FUNC_SIG __FUNC__
#elif defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901)
#define SN_FUNC_SIG __func__
#elif defined(__cplusplus) && (__cplusplus >= 201103)
#define SN_FUNC_SIG __func__
#else
#define SN_FUNC_SIG "SN_FUNC_SIG unknown!"
#endif

#define SN_PROFILE_BEGIN_SESSION(p_Name, p_FilePath) ::sn::Instrumentor::Instance().BeginSession(p_Name, p_FilePath)
#define SN_PROFILE_END_SESSION()                     ::sn::Instrumentor::Instance().EndSession()
#define SN_PROFILE_SCOPE_LINE2(p_Name, p_Line) \
                                                     constexpr auto fixedName##line = ::sn::InstrumentorUtils::CleanupOutputString(p_Name, "__cdecl "); \
                                                     ::sn::InstrumentationTimer timer##line(fixedName##line.Data)
#define SN_PROFILE_SCOPE_LINE(p_Name, p_Line)        SN_PROFILE_SCOPE_LINE2(p_Name, p_Line)
#define SN_PROFILE_SCOPE(p_Name)                     SN_PROFILE_SCOPE_LINE(p_Name, __LINE__)
#define SN_PROFILE_FUNCTION()                        SN_PROFILE_SCOPE(SN_FUNC_SIG)
#else
#define SN_PROFILE_BEGIN_SESSION(name, filepath)
#define SN_PROFILE_END_SESSION()
#define SN_PROFILE_SCOPE_LINE2(name, line)
#define SN_PROFILE_SCOPE_LINE(name, line)
#define SN_PROFILE_SCOPE(name)
#define SN_PROFILE_FUNCTION()
#endif