#
# InvokePython cli
#

cmake_minimum_required(VERSION 3.21)

add_executable(invokepython_cli)
target_sources(invokepython_cli PRIVATE
    main.cpp
)
target_include_directories(invokepython_cli PRIVATE
    ${PROJECT_SOURCE_DIR}/include
    ${PYTHON_BASE_DIR}/include/python3.9
)
target_link_libraries(invokepython_cli PRIVATE
    invokepython
)
target_compile_options(invokepython_cli PRIVATE
    -Wall
)