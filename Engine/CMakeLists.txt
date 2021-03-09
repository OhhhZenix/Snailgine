# Setups Engine
project(Snailgine-Engine)
message(STATUS "Setting up the Engine")

### Options ###
set(SN_ENABLE_PROFILE ON CACHE BOOL "Enable or disable the profiling" FORCE)
set(SN_GRAPHIC_BACKEND "OpenGL" CACHE STRING "Chooses which graphics backend to use" FORCE)

### Finding Package ###
if (SN_GRAPHIC_BACKEND STREQUAL "OpenGL")
    find_package(OpenGL REQUIRED)
endif ()

### Target ###
set(TARGET_NAME Snailgine)
add_library(
        ${TARGET_NAME}
        src/Core/Application.cpp
        src/Core/Input.cpp
        src/Core/Log.cpp
        src/Core/Window.cpp
        src/Debug/Instrumentor.cpp
        src/Event/App/AppRenderEvent.cpp
        src/Event/App/AppTickEvent.cpp
        src/Event/App/AppUpdateEvent.cpp
        src/Event/Keyboard/KeyEvent.cpp
        src/Event/Keyboard/KeyPressedEvent.cpp
        src/Event/Keyboard/KeyReleasedEvent.cpp
        src/Event/Keyboard/KeyTypedEvent.cpp
        src/Event/Mouse/MouseButtonEvent.cpp
        src/Event/Mouse/MouseButtonPressedEvent.cpp
        src/Event/Mouse/MouseButtonReleasedEvent.cpp
        src/Event/Mouse/MouseMovedEvent.cpp
        src/Event/Mouse/MouseScrolledEvent.cpp
        src/Event/Window/WindowCloseEvent.cpp
        src/Event/Window/WindowResizeEvent.cpp
        src/Event/Event.cpp
        src/Event/EventBaseFunction.cpp
        src/Event/EventBus.cpp
        src/Graphic/Context.cpp
        src/Graphic/Graphic.cpp
        src/Graphic/RenderCommand.cpp
        src/Graphic/Renderer.cpp
        src/Graphic/Shader.cpp
        src/ImGui/ImGuiLayer.cpp
        src/Layer/Layer.cpp
        src/Layer/LayerStack.cpp
)

if (SN_GRAPHIC_BACKEND STREQUAL "OpenGL")
    target_sources(
            ${TARGET_NAME}
            PRIVATE src/Graphic/OpenGL/OpenGL.cpp
            PRIVATE src/Graphic/OpenGL/OpenGLContext.cpp
            PRIVATE src/Graphic/OpenGL/OpenGLShader.cpp
    )
endif ()

if (WIN32)
    target_sources(
            ${TARGET_NAME}
            #PRIVATE src/Platform/Windows/WindowsInput.cpp
            PRIVATE src/Platform/Windows/WindowsWindow.cpp
    )
endif ()

### Target Include Directories ###
target_include_directories(${TARGET_NAME} PUBLIC include)

### Precompiled Header ###
target_precompile_headers(${TARGET_NAME} PRIVATE include/Snailgine/PCH.hpp)

### Linking Library ###
get_filename_component(PARENT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/.. ABSOLUTE)
set(EXTERN_PATH "${PARENT_DIR}/extern")

# spdlog
target_link_libraries(${TARGET_NAME} PUBLIC spdlog)

# imgui
target_link_libraries(${TARGET_NAME} PUBLIC imgui)

if (SN_GRAPHIC_BACKEND STREQUAL "OpenGL")
    target_link_libraries(${TARGET_NAME} PRIVATE OpenGL::GL)
    # target_link_libraries(${TARGET_NAME} PRIVATE glfw)
    target_link_libraries(${TARGET_NAME} PRIVATE glad)
endif ()

### Definitions ###
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