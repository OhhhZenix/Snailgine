# Setups Engine
project(Snailgine-Engine)
message(STATUS "Setting up the Engine")

# Options
option(SN_ENABLE_PROFILE "Enable or disable the profiling" ON)

# Finding spdlog
find_package(spdlog REQUIRED)

# Finding OpenGL
find_package(OpenGL REQUIRED)

# Finding glfw3
find_package(glfw3 REQUIRED)

# Finding glad
find_package(glad REQUIRED)

# Finding glm
find_package(glm REQUIRED)

# Finding imgui
find_package(imgui REQUIRED)

# Target
set(TARGET_NAME Snailgine)
add_library(
        ${TARGET_NAME}
        src/Snailgine/Core/Application.cpp
        src/Snailgine/Core/Application.hpp
        src/Snailgine/Core/Base.hpp
        src/Snailgine/Core/Log.cpp
        src/Snailgine/Core/Log.hpp
        src/Snailgine/Core/Window.cpp
        src/Snailgine/Core/Window.hpp
        src/Snailgine/Debug/Instrumentor.cpp
        src/Snailgine/Debug/Instrumentor.hpp
        src/Snailgine/Event/Window/WindowCloseEvent.cpp
        src/Snailgine/Event/Window/WindowCloseEvent.hpp
        src/Snailgine/Event/Window/WindowResizeEvent.cpp
        src/Snailgine/Event/Window/WindowResizeEvent.hpp
        src/Snailgine/Event/EventBaseFunction.cpp
        src/Snailgine/Event/EventBaseFunction.hpp
        src/Snailgine/Event/Event.cpp
        src/Snailgine/Event/Event.hpp
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
        src/Snailgine/Graphic/OpenGL/OpenGL.cpp
        src/Snailgine/Graphic/OpenGL/OpenGL.hpp
        src/Snailgine/Graphic/OpenGL/OpenGLContext.cpp
        src/Snailgine/Graphic/OpenGL/OpenGLContext.hpp
        src/Snailgine/ImGui/ImGuiLayer.cpp
        src/Snailgine/ImGui/ImGuiLayer.hpp
        src/Snailgine/Layer/Layer.cpp
        src/Snailgine/Layer/Layer.hpp
        src/Snailgine/Layer/LayerStack.cpp
        src/Snailgine/Layer/LayerStack.hpp
)

if (WIN32)
    target_sources(
            ${TARGET_NAME}
            PRIVATE src/Snailgine/Platform/Windows/WindowsWindow.cpp
            PRIVATE src/Snailgine/Platform/Windows/WindowsWindow.hpp
    )
endif()

# Includes the project include path
target_include_directories(${TARGET_NAME} PUBLIC src)

# Creates precompiled header
target_precompile_headers(${TARGET_NAME} PRIVATE src/Snailgine/PCH.hpp)

# Linking spdlog
target_link_libraries(${TARGET_NAME} PRIVATE spdlog::spdlog spdlog::spdlog_header_only)

# Linking OpenGL
target_link_libraries(${TARGET_NAME} PRIVATE OpenGL::GL)

# Linking glfw3
target_link_libraries(${TARGET_NAME} PRIVATE glfw)

# Linking glad
target_link_libraries(${TARGET_NAME} PRIVATE glad::glad)

# Linking glm
target_link_libraries(${TARGET_NAME} PUBLIC glm)

# Linking imgui
target_link_libraries(${TARGET_NAME} PRIVATE imgui::imgui)

# Custom definitions
target_compile_definitions(${TARGET_NAME} PRIVATE "GLFW_INCLUDE_NONE")

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(${TARGET_NAME} PRIVATE "SN_BUILD_DEBUG=1")
else ()
    target_compile_definitions(${TARGET_NAME} PRIVATE "SN_BUILD_DEBUG=0")
endif ()

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_definitions(${TARGET_NAME} PRIVATE "SN_BUILD_RELEASE=1")
else ()
    target_compile_definitions(${TARGET_NAME} PRIVATE "SN_BUILD_RELEASE=0")
endif ()

if (WIN32)
    target_compile_definitions(${TARGET_NAME} PRIVATE "SN_PLATFORM_WINDOW=1")
else ()
    target_compile_definitions(${TARGET_NAME} PRIVATE "SN_PLATFORM_WINDOW=0")
endif ()

if (SN_ENABLE_PROFILE EQUAL ON)
    target_compile_definitions(${TARGET_NAME} PRIVATE "SN_PROFILE=1")
else ()
    target_compile_definitions(${TARGET_NAME} PRIVATE "SN_PROFILE=0")
endif ()