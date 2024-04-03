cmake_minimum_required(VERSION 3.20)

project(terminal_display)

add_subdirectory(glfwpp)

add_subdirectory(terminal_display_vulkan_renderer)

add_library(terminal_display
    terminal_display.hpp
    terminal_display.cpp)
set_target_properties(terminal_display PROPERTIES CXX_STANDARD 23)

target_link_libraries(terminal_display PUBLIC glfwpp terminal_display_vulkan_renderer)
target_include_directories(terminal_display PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(RemoteTerminalDisplay
    main.cpp)
set_target_properties(RemoteTerminalDisplay PROPERTIES CXX_STANDARD 23)

target_link_libraries(RemoteTerminalDisplay PUBLIC terminal_display)
