#
# InvokePython
#
cmake_minimum_required(VERSION 3.21)
project(InvokePython
    VERSION 0.1.0
    DESCRIPTION "Invoke Python functions from C"
    LANGUAGES C CXX
)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Python3 embedライブラリを検索する.
# set(Python3_USE_STATIC_LIBS TRUE) # staticライブラリかsharedライブラリかを強制させられる
find_package (Python3 COMPONENTS Interpreter Development.Embed)
if (Python3_Development.Embed_FOUND)
    message(NOTICE "Python3 development artifacts for Python embedding found.")
else()
    message(FATAL_ERROR "Python3 development artifacts for Python embedding not found.")
endif()
message(NOTICE ${Python3_LIBRARIES})

# 面倒なのでグローバルでインクルードしてしまう
include_directories(BEFORE
    ${Python3_INCLUDE_DIRS}
)

# ライブラリソースディレクトリ
add_subdirectory(src)

# CLIソースディレクトリ
add_subdirectory(cli)

# 依存関係としてビルドされている場合は、tests/ を除外する
if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    option(INVOKEPYTHON_BUILD_TESTS "whether to build tests" ON)

    if(INVOKEPYTHON_BUILD_TESTS)
        message(NOTICE "testing enabled")
        enable_testing()
        add_subdirectory(tests)
    endif()
endif()
