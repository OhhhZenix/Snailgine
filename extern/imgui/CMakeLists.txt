cmake_minimum_required(VERSION 3.15 FATAL_ERROR)
project(imgui)

### Options ###
set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build shared" FORCE)
set(IMGUI_BUILD_EXAMPLES OFF CACHE BOOL "Build examples" FORCE)

### Target ###
add_library(
		${PROJECT_NAME}
		imgui/imgui.h
		imgui/imgui.cpp
		imgui/imconfig.h
		imgui/imgui_internal.h
		imgui/imgui_draw.cpp
		imgui/imgui_demo.cpp
		imgui/imgui_widgets.cpp
		imgui/imstb_rectpack.h
		imgui/imstb_textedit.h
		imgui/imstb_truetype.h
)
target_include_directories(${PROJECT_NAME} PUBLIC imgui)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

if (IMGUI_BUILD_EXAMPLES)
	message(STATUS "No examples currently working")
	# add_subdirectory(imgui/examples)
endif ()