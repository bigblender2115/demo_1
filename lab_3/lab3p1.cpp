#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <string>
#define N 1000000000
using namespace std;
using namespace std::chrono;
void merge(vector<int> &a, int l, int m, int h) {
    int i = l, j = m + 1, k = 0;
    int size = h - l + 1;
    vector<int> b(size);

    while (i <= m && j <= h) {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    while (i <= m) b[k++] = a[i++];
    while (j <= h) b[k++] = a[j++];

    for (i = 0; i < size; i++) {
        a[l + i] = b[i];
    }
}
void mergesort(vector<int> &a, int l, int h) {
    if (l < h) {
        int m = (l + h) / 2;
        mergesort(a, l, m);
        mergesort(a, m + 1, h);
        merge(a, l, m, h);
    }
}
int main() {
    vector<int> a(N / 10);
    int x;
    ofstream f1("input.txt");
    auto start = high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        x = rand() % N;
        f1 << x << " ";
    }
    f1.close();
    ifstream inFile("input.txt");
    for (int c = 0; c < 10; c++) {
        for (int i = 0; i < N / 10; i++) {
            inFile >> a[i];
        }

        mergesort(a, 0, N / 10 - 1);

        string fname = "output" + to_string(c + 1) + ".txt";
        ofstream fout(fname);
        for (int i = 0; i < N / 10; i++) {
            fout << a[i] << " ";
        }
        fout.close();
    }
    inFile.close();
    vector<ifstream> fins(10);
    for (int c = 0; c < 10; c++) {
        string fname = "output" + to_string(c + 1) + ".txt";
        fins[c].open(fname);
    }
    ofstream fout("Output.txt");
    vector<int> buffer(10);
    vector<bool> valid(10);
    for (int c = 0; c < 10; c++) {
        valid[c] = (fins[c] >> buffer[c]) ? true : false;
    }
    while (true) {
        int minIndex = -1;
        for (int c = 0; c < 10; c++) {
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
    for (int c = 0; c < 10; c++) fins[c].close();
    fout.close();
    auto stop = high_resolution_clock::now();
    auto elapsedtime = duration_cast<seconds>(stop - start);
    cout << "time taken: " << elapsedtime.count() << " s" << endl;
    return 0;
}