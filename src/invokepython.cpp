//
// InvokePython
//
#include "invokepython.hpp"

void exec_python_function() {
    // プログラム名を指定
    std::wstring programName = L"invoke_py_from_cpp.py";
    Py_SetProgramName(programName.c_str());

    // Pythonを初期化し
    Py_Initialize();

    // 単純なコードを実行
    PyRun_SimpleString("print(\"Hello, World from Python3 in C++!!\")");

    if (Py_FinalizeEx() < 0) {
        exit(120);
    }
}
