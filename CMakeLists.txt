# findq/CMakeLists.txt

cmake_minimum_required(VERSION 4.2)

project(findq)

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest
  GIT_TAG main
  GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(googletest)

add_subdirectory(src)

enable_testing()

