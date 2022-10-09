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
    ${PYTHON_BASE_DIR}/include/python3.9
)
target_link_libraries(invokepython PUBLIC
    ${PYTHON_BASE_DIR}/Python
)
target_compile_options(invokepython PRIVATE
    -Wall
)
