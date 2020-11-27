set(BINARY ${CMAKE_PROJECT_NAME})

set(SOURCES main.cpp MyClass.cpp MyClass.hpp)

add_executable(${BINARY} ${SOURCES})

add_library(${BINARY}_lib STATIC ${SOURCES})