#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
    int n = 100000000;
    vector<int> fib(n);
    fib[0] = 0;
    if (n > 1) fib[1] = 1;

    auto start = high_resolution_clock::now();

    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    // for (int i = 0; i < n; i++) {
    //     cout << fib[i] << " ";
    // }

    cout << "\nExecution time: " << duration.count() << " ms" << endl;
    return 0;
}
