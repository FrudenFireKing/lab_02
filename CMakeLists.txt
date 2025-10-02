cmake_minimum_required(VERSION 3.10)
project(lab_02)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Werror -Werror=maybe-uninitialized)
endif()

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.0
  TLS_VERIFY false
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_library(${CMAKE_PROJECT_NAME}_lib src/three.cpp)
target_include_directories(${CMAKE_PROJECT_NAME}_lib PUBLIC include)

add_executable(${CMAKE_PROJECT_NAME}_exe main.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME}_exe PRIVATE ${CMAKE_PROJECT_NAME}_lib)

enable_testing()

add_executable(tests test/test_three.cpp)
target_link_libraries(tests ${CMAKE_PROJECT_NAME}_lib gtest_main)
target_include_directories(tests PUBLIC include)

add_test(NAME ThreeClassTests COMMAND tests)