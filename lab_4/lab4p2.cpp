#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <string>
using namespace std;
using namespace chrono;

#define N 500000000
#define CHUNKS 10


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


void quicksort(vector<int> &arr, int start, int end) {
    if (start < end) {
        int pi = partition(arr, start, end);
        quicksort(arr, start, pi - 1);
        quicksort(arr, pi + 1, end);
    }
}


int main() {
    int chunkSize = N / CHUNKS;
    vector<int> arr(chunkSize);
    int x;

    auto start = high_resolution_clock::now();

    ofstream f1("input.txt");
    for (int i = 0; i < N; i++) {
        x = rand() % N;
        f1 << x << " ";
    }
    f1.close();

    ifstream inFile("input.txt");
    for (int c = 0; c < CHUNKS; c++) {
        for (int i = 0; i < chunkSize; i++) {
            inFile >> arr[i];
        }

        quicksort(arr, 0, chunkSize - 1);

        string fname = "chunk" + to_string(c + 1) + ".txt";
        ofstream fout(fname);
        for (int i = 0; i < chunkSize; i++) {
            fout << arr[i] << " ";
        }
        fout.close();
    }
    inFile.close();

    vector<ifstream> fins(CHUNKS);
    for (int c = 0; c < CHUNKS; c++) {
        string fname = "chunk" + to_string(c + 1) + ".txt";
        fins[c].open(fname);
    }

    ofstream fout("Output.txt");
    vector<int> buffer(CHUNKS);
    vector<bool> valid(CHUNKS);

    for (int c = 0; c < CHUNKS; c++) {
        valid[c] = (fins[c] >> buffer[c]) ? true : false;
    }

    while (true) {
        int minIndex = -1;
        for (int c = 0; c < CHUNKS; c++) {
            if (valid[c]) {
                if (minIndex == -1 || buffer[c] < buffer[minIndex]) {
                    minIndex = c;
                }
            }
        }
        if (minIndex == -1) break;

        fout << buffer[minIndex] << " ";
        valid[minIndex] = (fins[minIndex] >> buffer[minIndex]) ? true : false;
    }

    for (int c = 0; c < CHUNKS; c++) fins[c].close();
    fout.close();

    auto stop = high_resolution_clock::now();
    auto elapsed = duration_cast<seconds>(stop - start);
    cout << "time taken: " << elapsed.count() << "s" << endl;

    return 0;
}
