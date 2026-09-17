cmake_minimum_required(VERSION 3.21)
project(matching_engine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(ME_ENABLE_SANITIZERS "Build with AddressSanitizer + UndefinedBehaviorSanitizer" OFF)
option(ME_BUILD_TESTS "Build unit tests" ON)

add_library(matching_engine_core INTERFACE)
target_include_directories(matching_engine_core INTERFACE ${CMAKE_SOURCE_DIR}/include)
target_compile_options(matching_engine_core INTERFACE -Wall -Wextra -Wpedantic)

if(ME_ENABLE_SANITIZERS)
  target_compile_options(matching_engine_core INTERFACE -fsanitize=address,undefined -fno-omit-frame-pointer)
  target_link_options(matching_engine_core INTERFACE -fsanitize=address,undefined)
endif()

if(ME_BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()
