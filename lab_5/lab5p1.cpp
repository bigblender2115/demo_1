#include <iostream>
#include <vector>
using namespace std;

void coinchange(vector<int> coins, int amt) {
    vector<int> count(coins.size(), 0);

    for(int i = 0; i < coins.size(); i++) {
        while(amt >= coins[i]) {
            amt -= coins[i];
            count[i]++;
        }
    }
    int total = 0;
    for(int c : count) total += c;
    cout << total << " coins of ";
    for (int i = 0; i < coins.size(); i++) {
        if(count[i] > 0) {
            cout << coins[i] << "x" << count[i] << " ";
        }
    }
    cout << " are used";
}

int main() {
    vector<int> coins = {20, 10, 5, 2, 1};
    int amt = 124;
    coinchange(coins, amt);
    return 0;
}