cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
set(CMAKE_C_FLAGS "-O0 -g ${CMAKE_C_FLAGS}" )
set(CMAKE_CXX_FLAGS "-O0 -g ${CMAKE_CXX_FLAGS}")

set(SOURCES
    "main.cpp"
    "utils.cpp"
    "inheritance.cpp"
    )

set(HEADERS
    "utils.h"
    "learning.h"
    )


project(learning)
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME}
    pthread
    )
