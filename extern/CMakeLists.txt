# spdlog
set(SPDLOG_INSTALL OFF CACHE BOOL "" FORCE)
set(SPDLOG_BUILD_BENCH OFF CACHE BOOL "" FORCE)
set(SPDLOG_BUILD_EXAMPLE OFF CACHE BOOL "" FORCE)
set(SPDLOG_BUILD_EXAMPLE_HO OFF CACHE BOOL "" FORCE)
set(SPDLOG_BUILD_SHARED OFF CACHE BOOL "" FORCE)
set(SPDLOG_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(SPDLOG_BUILD_TESTS_HO OFF CACHE BOOL "" FORCE)
add_subdirectory(spdlog)
set_target_properties(spdlog PROPERTIES FOLDER extern)

# glad
set(GLAD_PROFILE "core" CACHE STRING "" FORCE)
set(GLAD_API "gl=4.5" CACHE STRING "" FORCE)
set(GLAD_INSTALL OFF CACHE BOOL "" FORCE)
add_subdirectory(glad)
set_target_properties(glad PROPERTIES FOLDER extern)
set_target_properties(glad-generate-files PROPERTIES FOLDER extern)

# imgui
set(IMGUI_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(imgui)
set_target_properties(imgui PROPERTIES FOLDER extern)