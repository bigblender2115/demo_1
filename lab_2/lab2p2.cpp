#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

int main() {
    long long n = 1000000000;
    long long x = 0;

    auto start = high_resolution_clock::now();

    long long low = 0, high = n - 1;
    bool found = false;
    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (mid == x) {
            cout << "target at index: " << mid << endl;
            found = true;
            break;
        }
        else if (mid < x) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    if (!found) {
        cout << "Target " << x << " not found!" << endl;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "Execution time: " << duration.count() << " ns" << endl;

    return 0;
}
