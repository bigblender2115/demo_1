#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

long long BSrec(long long low, long long high, long long x, bool &check) {
    if (low > high){
        return -1;
    }

    long long mid = low + (high - low) / 2;
    if (mid == x) {
        check = true;
        return mid;
    }
    else if (mid < x) {
        return BSrec(mid + 1, high, x, check);
    }
    else {
        return BSrec(low, mid - 1, x, check);
    }
}

int main() {
    long long n = 1000000000;
    long long x = 10;

    auto start = high_resolution_clock::now();

    bool check = false;
    long long result = BSrec(0, n - 1, x, check);

    if (check) {
        cout << "target at index: " << result << endl;
    } else {
        cout << "target not found" << endl;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "execution time: " << duration.count() << " ns" << endl;

    return 0;
}