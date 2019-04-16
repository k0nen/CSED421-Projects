cmake_minimum_required (VERSION 2.6)
project (InMemoryBPtree)

add_executable(workload "./main.cpp")
target_compile_options(workload PRIVATE -O3)
target_compile_definitions(workload PRIVATE -DNDEBUG)
