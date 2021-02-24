#include "Instrumentor.hpp"

namespace sn
{
	Instrumentor::Instrumentor()
	{
		m_CurrentSession = nullptr;
	}

	Instrumentor::~Instrumentor()
	{
		EndSession();
	}

	Instrumentor& Instrumentor::Instance()
	{
		static Instrumentor s_Instance;
		return s_Instance;
	}

	void Instrumentor::BeginSession(const std::string& p_Name, const std::string& p_FilePath)
	{
		std::lock_guard lock(m_Mutex);
		if (m_CurrentSession)
		{
			// If there is already a current session, then close it before beginning new one.
			// Subsequent profiling output meant for the original session will end up in the
			// newly opened session instead.  That's better than having badly formatted
			// profiling output.
/*			if (Log::GetCoreLogger()) // Edge case: BeginSession() might be before Log::Init()
			{
				SN_LOG_ERROR("Instrumentor::BeginSession('{0}') when session '{1}' already open.", p_Name, m_CurrentSession
					->Name);
			}*/
			InternalEndSession();
		}
		m_OutputStream.open(p_FilePath);

		if (m_OutputStream.is_open())
		{
			m_CurrentSession = new InstrumentationSession({ p_Name });
			WriteHeader();
		}
		else
		{
/*			if (Log::GetCoreLogger()) // Edge case: BeginSession() might be before Log::Init()
			{
				SN_LOG_ERROR("Instrumentor could not open results file '{0}'.", p_FilePath);
			}*/
		}
	}

	void Instrumentor::EndSession()
	{
		std::lock_guard lock(m_Mutex);
		InternalEndSession();
	}

	void Instrumentor::WriteProfile(const ProfileResult& p_Result)
	{
		std::stringstream f_Json;

		f_Json << std::setprecision(3) << std::fixed;
		f_Json << ",{";
		f_Json << R"("cat":"function",)";
		f_Json << "\"dur\":" << (p_Result.ElapsedTime.count()) << ',';
		f_Json << R"("name":")" << p_Result.Name << "\",";
		f_Json << R"("ph":"X",)";
		f_Json << "\"pid\":0,";
		f_Json << "\"tid\":" << p_Result.ThreadID << ",";
		f_Json << "\"ts\":" << p_Result.Start.count();
		f_Json << "}";

		std::lock_guard lock(m_Mutex);
		if (m_CurrentSession)
		{
			m_OutputStream << f_Json.str();
			m_OutputStream.flush();
		}
	}

	void Instrumentor::WriteHeader()
	{
		m_OutputStream << R"({"otherData": {},"traceEvents":[{})";
		m_OutputStream.flush();
	}

	void Instrumentor::WriteFooter()
	{
		m_OutputStream << "]}";
		m_OutputStream.flush();
	}

	void Instrumentor::InternalEndSession()
	{
		if (m_CurrentSession)
		{
			WriteFooter();
			m_OutputStream.close();
			delete m_CurrentSession;
			m_CurrentSession = nullptr;
		}
	}

	InstrumentationTimer::InstrumentationTimer(const char* p_Name)
	{
		m_Name = p_Name;
		m_Stopped = false;
		m_StartTimePoint = std::chrono::steady_clock::now();
	}

	InstrumentationTimer::~InstrumentationTimer()
	{
		if (!m_Stopped)
			Stop();
	}

	void InstrumentationTimer::Stop()
	{
		auto f_EndTimePoint = std::chrono::steady_clock::now();
		auto f_HighResStart = FloatingPointMicroseconds{ m_StartTimePoint.time_since_epoch() };
		auto f_ElapsedTime = std::chrono::time_point_cast<std::chrono::microseconds>(f_EndTimePoint).time_since_epoch() - std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimePoint).time_since_epoch();

		Instrumentor::Instance().WriteProfile({ m_Name, f_HighResStart, f_ElapsedTime, std::this_thread::get_id() });

		m_Stopped = true;
	}
}