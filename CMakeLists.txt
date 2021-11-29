cmake_minimum_required(VERSION 3.1)
project(OneWeekend VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES src/main.cpp)
set(LIBRARY_NAME ray_trace_utils)

include_directories(
                    src
                    src/Utils)

add_subdirectory(src/Utils/tests)
add_subdirectory(src/Utils)

add_executable(OneWeekend ${SOURCE_FILES})
target_link_libraries(OneWeekend ${LIBRARY_NAME})