#
# InvokePython sources
#

cmake_minimum_required(VERSION 3.21)

add_library(invokepython)
target_sources(invokepython PRIVATE
    invokepython.cpp
)
target_include_directories(invokepython PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)
target_link_libraries(invokepython PUBLIC
    Python3::Python
)
target_compile_options(invokepython PRIVATE
    -Wall
)
