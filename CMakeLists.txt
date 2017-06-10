cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

project("more-lights")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE SOURCE_FILES "Sources/*.cpp")

add_definitions(-DUNICODE -D_UNICODE)

add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE 
  "${CMAKE_SOURCE_DIR}/Sources"
  )

target_compile_options(${PROJECT_NAME} PRIVATE "/W4")
