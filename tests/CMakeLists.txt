#
# InvokePython tests
#
cmake_minimum_required(VERSION 3.21)

# GoogleTestのフェッチと有効化
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

## 外部依存関係を追加...

# テストターゲットの構成
add_executable(invokepython_test)
target_sources(invokepython_test PRIVATE
    test_invokepython.cpp
)
target_link_libraries(invokepython_test PRIVATE
    invokepython
    GTest::gtest_main
)
target_include_directories(invokepython_test
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include
    ${GTEST_INCLUDE_DIRS}
)

# テストの実行
gtest_discover_tests(invokepython_test)