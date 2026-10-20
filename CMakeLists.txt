cmake_minimum_required(VERSION 3.10.0)
project(simd_threads LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Threads REQUIRED)

add_executable(simd_threads
    main.cpp
    single.cpp
    threads.cpp
    threads_simd.cpp
    matrix.cpp
)

target_link_libraries(simd_threads PRIVATE Threads::Threads)
set_source_files_properties(threads_simd.cpp
    PROPERTIES COMPILE_OPTIONS "-mavx2"
)


