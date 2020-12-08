set(BINARY ${CMAKE_PROJECT_NAME}_test)

set(TEST_SOURCES catch_amalgamated.cpp catch_amalgamated.hpp main.cpp SampleTests.cpp)

set(SOURCES ${TEST_SOURCES})

add_executable(${BINARY} ${TEST_SOURCES})
target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib)