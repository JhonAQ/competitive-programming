#include <iostream>
#include <cstdio>
#include <fstream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include "core.h"

using namespace std;

int executeWithCode(const char* cmd) {
    auto pipe = popen(cmd, "r"); // get rid of shared_ptr

    if (!pipe) throw std::runtime_error("popen() failed!");

    auto rc = pclose(pipe);
    return rc == EXIT_SUCCESS;
}

int liveLog(const char* cmd) {
    array<char, 128> buffer;
    string result;
    std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);

    if (!pipe) {
        return false;
    }

    while (!feof(pipe.get())) {
        if (fgets(buffer.data(), 128, pipe.get()) != nullptr) {
            // live logging the output of process
            result = buffer.data();
            cout << result;
        }
    }

    return true;
}