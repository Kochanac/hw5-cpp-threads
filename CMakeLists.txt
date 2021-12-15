cmake_minimum_required(VERSION 3.0)

project(
        acs-5
        VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(Threads REQUIRED)

file(GLOB SRC
        "src/*.h"
        "src/*.cpp"
        )

add_executable(numbers ${SRC})

target_link_libraries(numbers PRIVATE Threads::Threads)
