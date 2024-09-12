#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {
    auto start = high_resolution_clock::now();
    for (int i = 0; i < 1000000000; ++i) {
        (i & 1);
    }
    auto end = high_resolution_clock::now();

    duration<double> bitwise_duration = end - start;

    cout << "Tiempo bitwise: " << bitwise_duration.count() << " segundos" << endl;

    start = high_resolution_clock::now();
    for (int i = 0; i < 1000000000; ++i) {
        (i % 2);
    }
    end = high_resolution_clock::now();
    duration<double> modulo_duration = end - start;
    cout << "Tiempo módulo: " << modulo_duration.count() << " segundos" << endl;

    return 0;
}
