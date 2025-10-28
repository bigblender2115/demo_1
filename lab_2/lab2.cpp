#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

int main() {
    long long n = 1000000000;
    int x = 50;
    int check = false;

    auto start = high_resolution_clock::now();

    for(long long i = 0; i < n; i++){
        int val = rand();
        if(val == x){
            cout << "target at: " << i << endl;
            check = !check;
            break;
        } 
    }

    if(!check){
        cout << "target not in array";
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "execution time: " << duration.count() << " ns" << endl;
    return 0;
}

