# findq/parser/CMakeLists.txt

project(findq_parser_bison)

add_executable(findqparser findq_parser.cpp)

target_compile_definitions(findqparser PRIVATE
  $<$<PLATFORM_ID:CYGWIN>: GTEST_HAS_PTHREAD=1 _POSIX_C_SOURCE=200809L _GNU_SOURCE>
)

target_compile_options(findqparser PRIVATE
  $<$<CXX_COMPILER_ID:GNU>: -Wall -Werror -Wextra -std=c++26 -pthread -fconcepts-diagnostics-depth=10>
  $<$<CXX_COMPILER_ID:MSVC>: -std:c++latest -W4 -WX>
  $<$<CXX_COMPILER_ID:Clang>: -Wall -Werror -Wextra -std=c++26 -pthread -Wno-unqualified-std-cast-call>
)
target_compile_options(findqparser PRIVATE
  $<$<AND:$<CONFIG:debug>,$<CXX_COMPILER_ID:GNU>>: -O0 -ggdb3>
  $<$<AND:$<CONFIG:release>,$<CXX_COMPILER_ID:GNU>>: -Og>
  $<$<AND:$<CONFIG:debug>,$<CXX_COMPILER_ID:MSVC>>: -Od -Zi>
  $<$<AND:$<CONFIG:debug>,$<CXX_COMPILER_ID:Clang>>: -O0 -ggdb3>
  $<$<AND:$<CONFIG:release>,$<CXX_COMPILER_ID:Clang>>: -Og>
)

target_link_libraries(findqparser findqastlib flexbisonlib.findqparser)
target_link_libraries(findqparser $<$<CXX_COMPILER_ID:MSVC>: getoptlib>)

# tests

add_executable(findq_parser.gtest findq_parser.gtest.cpp)

target_compile_definitions(findq_parser.gtest PRIVATE $<$<PLATFORM_ID:CYGWIN>: GTEST_HAS_PTHREAD=1 _POSIX_C_SOURCE=200809L _GNU_SOURCE>)

target_compile_options(findq_parser.gtest PRIVATE
  $<$<CXX_COMPILER_ID:GNU>: -Wall -Werror -Wextra -std=c++26 -pthread -fconcepts-diagnostics-depth=10>
  $<$<CXX_COMPILER_ID:MSVC>: -std:c++latest -W4 -WX>
  $<$<CXX_COMPILER_ID:Clang>: -Wall -Werror -Wextra -std=c++26 -pthread -Wno-unqualified-std-cast-call>
)
target_compile_options(findq_parser.gtest PRIVATE
  $<$<AND:$<CONFIG:debug>,$<CXX_COMPILER_ID:GNU>>: -O0 -ggdb3>
  $<$<AND:$<CONFIG:release>,$<CXX_COMPILER_ID:GNU>>: -Og>
  $<$<AND:$<CONFIG:debug>,$<CXX_COMPILER_ID:MSVC>>: -Od -Zi>
  $<$<AND:$<CONFIG:debug>,$<CXX_COMPILER_ID:Clang>>: -O0 -ggdb3>
  $<$<AND:$<CONFIG:release>,$<CXX_COMPILER_ID:Clang>>: -Og>
)

target_link_libraries(findq_parser.gtest findqastlib flexbisonlib.findqparser gmock_main)

enable_testing()
include(GoogleTest)
gtest_discover_tests(findq_parser.gtest DISCOVERY_MODE PRE_TEST EXTRA_ARGS --gtest_color=yes)

