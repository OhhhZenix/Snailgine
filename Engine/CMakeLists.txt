# Setups Engine
project(Snailgine-Engine)
message(STATUS "Setting up the Engine")

# Options
set(SN_ENABLE_PROFILE ON CACHE BOOL "Enable or disable the profiling" FORCE)
set(SN_GRAPHIC_BACKEND "OpenGL" CACHE STRING "Chooses which graphics backend to use" FORCE)

# Finding spdlog
find_package(spdlog CONFIG REQUIRED)

# Finding OpenGL
find_package(OpenGL REQUIRED)

# Finding glfw3
find_package(glfw3 CONFIG REQUIRED)

# Finding glad
find_package(glad CONFIG REQUIRED)

# Finding imgui
find_package(imgui CONFIG REQUIRED)

# Target
set(TARGET_NAME Snailgine)
add_library(
        ${TARGET_NAME}
        src/Snailgine/Core/Application.cpp
        src/Snailgine/Core/Application.hpp
        src/Snailgine/Core/Base.hpp
        src/Snailgine/Core/Input.cpp
        src/Snailgine/Core/Input.hpp
        src/Snailgine/Core/KeyCode.hpp
        src/Snailgine/Core/Log.cpp
        src/Snailgine/Core/Log.hpp
        src/Snailgine/Core/MouseCode.hpp
        src/Snailgine/Core/Window.cpp
        src/Snailgine/Core/Window.hpp
        src/Snailgine/Debug/Instrumentor.cpp
        src/Snailgine/Debug/Instrumentor.hpp
        src/Snailgine/Event/App/AppRenderEvent.cpp
        src/Snailgine/Event/App/AppRenderEvent.hpp
        src/Snailgine/Event/App/AppTickEvent.cpp
        src/Snailgine/Event/App/AppTickEvent.hpp
        src/Snailgine/Event/App/AppUpdateEvent.cpp
        src/Snailgine/Event/App/AppUpdateEvent.hpp
        src/Snailgine/Event/Keyboard/KeyEvent.cpp
        src/Snailgine/Event/Keyboard/KeyEvent.hpp
        src/Snailgine/Event/Keyboard/KeyPressedEvent.cpp
        src/Snailgine/Event/Keyboard/KeyPressedEvent.hpp
        src/Snailgine/Event/Keyboard/KeyReleasedEvent.cpp
        src/Snailgine/Event/Keyboard/KeyReleasedEvent.hpp
        src/Snailgine/Event/Keyboard/KeyTypedEvent.cpp
        src/Snailgine/Event/Mouse/MouseButtonEvent.cpp
        src/Snailgine/Event/Mouse/MouseButtonEvent.hpp
        src/Snailgine/Event/Mouse/MouseButtonPressedEvent.cpp
        src/Snailgine/Event/Mouse/MouseButtonPressedEvent.hpp
        src/Snailgine/Event/Mouse/MouseButtonReleasedEvent.cpp
        src/Snailgine/Event/Mouse/MouseButtonReleasedEvent.hpp
        src/Snailgine/Event/Mouse/MouseMovedEvent.cpp
        src/Snailgine/Event/Mouse/MouseMovedEvent.hpp
        src/Snailgine/Event/Mouse/MouseScrolledEvent.cpp
        src/Snailgine/Event/Mouse/MouseScrolledEvent.hpp
        src/Snailgine/Event/Keyboard/KeyTypedEvent.hpp
        src/Snailgine/Event/Window/WindowCloseEvent.cpp
        src/Snailgine/Event/Window/WindowCloseEvent.hpp
        src/Snailgine/Event/Window/WindowResizeEvent.cpp
        src/Snailgine/Event/Window/WindowResizeEvent.hpp
        src/Snailgine/Event/Event.cpp
        src/Snailgine/Event/Event.hpp
        src/Snailgine/Event/EventBaseFunction.cpp
        src/Snailgine/Event/EventBaseFunction.hpp
        src/Snailgine/Event/EventBus.cpp
        src/Snailgine/Event/EventBus.hpp
        src/Snailgine/Event/EventMemberFunction.hpp
        src/Snailgine/Graphic/Context.cpp
        src/Snailgine/Graphic/Context.hpp
        src/Snailgine/Graphic/Graphic.cpp
        src/Snailgine/Graphic/Graphic.hpp
        src/Snailgine/Graphic/RenderCommand.cpp
        src/Snailgine/Graphic/RenderCommand.hpp
        src/Snailgine/Graphic/Renderer.cpp
        src/Snailgine/Graphic/Renderer.hpp
        src/Snailgine/Graphic/Shader.cpp
        src/Snailgine/Graphic/Shader.hpp
        src/Snailgine/ImGui/ImGuiLayer.cpp
        src/Snailgine/ImGui/ImGuiLayer.hpp
        src/Snailgine/Layer/Layer.cpp
        src/Snailgine/Layer/Layer.hpp
        src/Snailgine/Layer/LayerStack.cpp
        src/Snailgine/Layer/LayerStack.hpp
        src/Snailgine/Math/Mat4.hpp
        src/Snailgine/Math/Vec2.hpp
        src/Snailgine/Math/Vec3.hpp
        src/Snailgine/Math/Vec4.hpp
)

if (SN_GRAPHIC_BACKEND STREQUAL "OpenGL")
    target_sources(
            ${TARGET_NAME}
            PRIVATE src/Snailgine/Graphic/OpenGL/OpenGL.cpp
            PRIVATE src/Snailgine/Graphic/OpenGL/OpenGL.hpp
            PRIVATE src/Snailgine/Graphic/OpenGL/OpenGLContext.cpp
            PRIVATE src/Snailgine/Graphic/OpenGL/OpenGLContext.hpp
            PRIVATE src/Snailgine/Graphic/OpenGL/OpenGLShader.cpp
            PRIVATE src/Snailgine/Graphic/OpenGL/OpenGLShader.hpp
    )
endif ()

if (WIN32)
    target_sources(
            ${TARGET_NAME}
            PRIVATE src/Snailgine/Platform/Windows/WindowsInput.cpp
            PRIVATE src/Snailgine/Platform/Windows/WindowsInput.hpp
            PRIVATE src/Snailgine/Platform/Windows/WindowsWindow.cpp
            PRIVATE src/Snailgine/Platform/Windows/WindowsWindow.hpp
    )
endif()

# Includes the project include path
target_include_directories(${TARGET_NAME} PUBLIC src)

# Creates precompiled header
target_precompile_headers(${TARGET_NAME} PRIVATE src/Snailgine/PCH.hpp)

# Linking spdlog
target_link_libraries(${TARGET_NAME} PUBLIC spdlog::spdlog spdlog::spdlog_header_only)

# Linking OpenGL
target_link_libraries(${TARGET_NAME} PRIVATE OpenGL::GL)

# Linking glfw3
target_link_libraries(${TARGET_NAME} PRIVATE glfw)

# Linking glad
target_link_libraries(${TARGET_NAME} PRIVATE glad::glad)

# Linking imgui
target_link_libraries(${TARGET_NAME} PUBLIC imgui::imgui)

# Custom definitions
target_compile_definitions(${TARGET_NAME} PRIVATE "GLFW_INCLUDE_NONE")

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(${TARGET_NAME} PUBLIC "SN_BUILD_DEBUG=1")
else ()
    target_compile_definitions(${TARGET_NAME} PUBLIC "SN_BUILD_DEBUG=0")
endif ()

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_definitions(${TARGET_NAME} PUBLIC "SN_BUILD_RELEASE=1")
else ()
    target_compile_definitions(${TARGET_NAME} PUBLIC "SN_BUILD_RELEASE=0")
endif ()

if (WIN32)
    target_compile_definitions(${TARGET_NAME} PUBLIC "SN_PLATFORM_WINDOW=1")
else ()
    target_compile_definitions(${TARGET_NAME} PUBLIC "SN_PLATFORM_WINDOW=0")
endif ()

if (SN_ENABLE_PROFILE EQUAL ON)
    target_compile_definitions(${TARGET_NAME} PUBLIC "SN_PROFILE=1")
else ()
    target_compile_definitions(${TARGET_NAME} PUBLIC "SN_PROFILE=0")
endif ()