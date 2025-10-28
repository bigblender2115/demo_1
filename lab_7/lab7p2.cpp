#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n = 4;
    int profit[] = {100, 10, 15, 27};
    int deadline[] = {2, 1, 2, 1};

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (profit[i] < profit[j]) {
                swap(profit[i], profit[j]);
                swap(deadline[i], deadline[j]);
            }
        }
    }

    int thedeadline = 0;
    for (int i = 0; i < n; i++) {
        thedeadline = max(thedeadline, deadline[i]);
    }

    int slot[thedeadline + 1];
    for (int i = 0; i <= thedeadline; i++) {
        slot[i] = -1;
    }

    int tprofit = 0;

    for (int i = 0; i < n; i++) {
        for (int t = deadline[i]; t > 0; t--) {
            if (slot[t] == -1) {
                slot[t] = i;
                tprofit += profit[i];
                break;
            }
        }
    }

    for (int i = 1; i <= thedeadline; i++) {
        if (slot[i] != -1)
            cout << slot[i] + 1 << " ";
    }
    cout << endl;
    cout << "profit: " << tprofit << endl;
}