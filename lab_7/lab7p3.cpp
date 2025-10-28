#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n = 100000;

    auto start = high_resolution_clock::now();

    for (int i = 0; i < n; i++) {
        fib(i);
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start);

    cout << "\nexecution time: " << duration.count() << " s" << endl;
    return 0;
}
