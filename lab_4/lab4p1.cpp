#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

int partition(vector<int> &arr, int start, int end) {
    int pivot = arr[end];
    int i = start - 1;

    for (int j = start; j < end; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[end]);
    return i + 1;
}

void qs(vector<int> &arr, int start, int end) {
    if (start < end) {
        int pi = partition(arr, start, end);
        qs(arr, start, pi - 1);
        qs(arr, pi + 1, end);
    }
}

int main() {
    int N = 100000000;
    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
        arr[i] = rand() % N;
    }

    auto start = high_resolution_clock::now();

    qs(arr, 0, arr.size() - 1);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start);
    cout << "execution time: " << duration.count() << "s" << endl;
    return 0;
}