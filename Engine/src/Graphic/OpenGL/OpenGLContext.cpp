#include "Snailgine/Graphic/OpenGL/OpenGLContext.hpp"

#include <glad/glad.h>
#include "Snailgine/Core/Log.hpp"

#if defined(SN_PLATFORM_WINDOW)

#include <Windows.h>

#endif

namespace sn
{
#if defined(SN_PLATFORM_WINDOW)
    static HDC s_HDC = nullptr;
    static HGLRC s_OpenGLContext = nullptr;
#endif

    OpenGLContext::OpenGLContext(void*p_Window)
    {
        m_Window = p_Window;
        SN_LOG_ASSERT(p_Window,
                      "Window handle is null!");

        SN_PROFILE_FUNCTION();

#if defined(SN_PLATFORM_WINDOW)
        s_HDC = GetDC(static_cast<HWND>(m_Window));
        SN_LOG_ASSERT(s_HDC != nullptr,
                      "failed to get window's device context");

        PIXELFORMATDESCRIPTOR f_PixelFormatDescriptor = {};
        f_PixelFormatDescriptor.nSize = sizeof(f_PixelFormatDescriptor);
        f_PixelFormatDescriptor.nSize = sizeof(PIXELFORMATDESCRIPTOR);
        f_PixelFormatDescriptor.dwFlags = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;
        f_PixelFormatDescriptor.iPixelType = PFD_TYPE_RGBA;
        f_PixelFormatDescriptor.cColorBits = 32;
        f_PixelFormatDescriptor.cDepthBits = 32;
        f_PixelFormatDescriptor.iLayerType = PFD_MAIN_PLANE;
        int f_PixelFormat = ChoosePixelFormat(s_HDC,
                                              &f_PixelFormatDescriptor);
        int f_SetPixelFormat = SetPixelFormat(s_HDC,
                                              f_PixelFormat,
                                              &f_PixelFormatDescriptor);
        SN_LOG_ASSERT(f_PixelFormat != 0 && f_SetPixelFormat != 0,
                      "failed to set pixel format");

        s_OpenGLContext = wglCreateContext(s_HDC);
        SN_LOG_ASSERT(s_OpenGLContext != nullptr,
                      "failed to create final rendering context");
        wglMakeCurrent(s_HDC,
                       s_OpenGLContext);

        int f_GLADLoadGL = gladLoadGL();
        SN_LOG_ASSERT(f_GLADLoadGL,
                      "failed to load GL");
#endif

        SN_LOG_INFO("OpenGL Info:");
        SN_LOG_INFO("  Vendor: {0}",
                    glGetString(GL_VENDOR));
        SN_LOG_INFO("  Renderer: {0}",
                    glGetString(GL_RENDERER));
        SN_LOG_INFO("  Version: {0}",
                    glGetString(GL_VERSION));

        SN_LOG_ASSERT(GLVersion.major > 4 || (GLVersion.major == 4 && GLVersion.minor
                                                                      >= 5),
                      "Snailgine requires at least OpenGL version 4.5!");
    }

    OpenGLContext::~OpenGLContext()
    {
#if defined(SN_PLATFORM_WINDOW)
        wglDeleteContext(s_OpenGLContext);
        ReleaseDC(static_cast<HWND>(m_Window),
                  s_HDC);
#endif
    }

    void OpenGLContext::SwapBuffers()
    {
        SN_PROFILE_FUNCTION();

#if defined(SN_PLATFORM_WINDOW)
        ::SwapBuffers(s_HDC);
#endif
    }
}