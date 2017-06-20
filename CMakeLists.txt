cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

project("more-lights")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE SOURCES "Sources/*.cpp")

find_package(Vulkan REQUIRED)
add_executable(${PROJECT_NAME} WIN32 ${SOURCES})

target_include_directories(${PROJECT_NAME} SYSTEM PUBLIC
  "${CMAKE_SOURCE_DIR}/External/glm/"
  "${Vulkan_INCLUDE_DIRS}"
  )

target_link_libraries(${PROJECT_NAME} ${Vulkan_LIBRARY})

target_include_directories(${PROJECT_NAME} PRIVATE 
  "${CMAKE_SOURCE_DIR}/Sources"
  )

target_compile_definitions(${PROJECT_NAME} PRIVATE "UNICODE" "_UNICODE")
target_compile_options(${PROJECT_NAME} PRIVATE "/W4")
