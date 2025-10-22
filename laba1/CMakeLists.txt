cmake_minimum_required(VERSION 3.12)
project(lab01)

set(CMAKE_CXX_STANDARD 17)

add_executable(program1 main.cpp laba1.cpp)

# настройка GTest 
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)


include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest) #даем доспупно дял пользователя

#тестовый исполняемый файл
add_executable(laba1_tests test_laba1.cpp laba1.cpp)
target_link_libraries(laba1_tests PRIVATE gtest_main)