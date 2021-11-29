set(HEADER_FILES 
    catch.hpp
    )

set(SOURCE_FILES 
    vec3_tests.cpp
    ray_tests.cpp
    )


set(LIBRARY_NAME ray_trace_utils)

add_executable(tests ${SOURCE_FILES})
target_link_libraries(tests ${LIBRARY_NAME})