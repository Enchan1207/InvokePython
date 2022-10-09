#
# InvokePython sources
#

cmake_minimum_required(VERSION 3.21)

## 外部依存関係を追加...

add_library(invokepython)
target_sources(invokepython PRIVATE
    invokepython.cpp
)
target_include_directories(invokepython PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)
target_compile_options(invokepython PRIVATE
    -Wall
)