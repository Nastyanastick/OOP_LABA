cmake_minimum_required(VERSION 3.12)
project(laba2oop)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# настройка GTest 
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)


include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

#тестовый исполняемый файл
add_executable(laba2_tests test_laba2.cpp laba2.cpp)
target_link_libraries(laba2_tests PRIVATE gtest_main)
target_include_directories(laba2_tests PRIVATE ${PROJECT_SOURCE_DIR})
