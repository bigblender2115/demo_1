#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void greedyByProfit(vector<float> weight, vector<float> profit, int cap) {
    int n = weight.size();

    vector<vector<double>> items(n, vector<double>(2));
    for (int i = 0; i < n; i++) {
        items[i][0] = weight[i];
        items[i][1] = profit[i];
    }

    sort(items.begin(), items.end(), [](auto &a, auto &b) {
        return a[1] > b[1];
    });

    float totalProfit = 0, totalWeight = 0;

    
    for (int i = 0; i < n; i++) {
        if (totalWeight + items[i][0] <= cap) {
            totalWeight += items[i][0];
            totalProfit += items[i][1];
            cout << "(" << items[i][0] << ", " << items[i][1] << ", 1.00)\n";
        } else {
            float remain = cap - totalWeight;
            float fraction = remain / items[i][0];
            totalProfit += items[i][1] * fraction;
            totalWeight += remain;
            cout << "(" << items[i][0] << ", " << items[i][1] << ", " << fraction << ")\n";
            break;
        }
    }
    cout << "Total Profit = " << totalProfit << "\n";
}

void greedyByWeight(vector<float> weight, vector<float> profit, float cap) {
    int n = weight.size();

    vector<vector<float>> items(n, vector<float>(2));
    for (int i = 0; i < n; i++) {
        items[i][0] = weight[i];
        items[i][1] = profit[i];
    }

    sort(items.begin(), items.end(), [](auto &a, auto &b) {
        return a[0] < b[0];
    });

    float totalProfit = 0, totalWeight = 0;

    for (int i = 0; i < n; i++) {
        if (totalWeight + items[i][0] <= cap) {
            totalWeight += items[i][0];
            totalProfit += items[i][1];
            cout << "(" << items[i][0] << ", " << items[i][1] << ", 1.00)\n";
        } else {
            float remain = cap - totalWeight;
            float fraction = remain / items[i][0];
            totalProfit += items[i][1] * fraction;
            totalWeight += remain;
            cout << "(" << items[i][0] << ", " << items[i][1] << ", " << fraction << ")\n";
            break;
        }
    }

    cout << "Total Profit = " << totalProfit << "\n";
}

void greedyByBoth(vector<float> weight, vector<float> profit, float cap) {
    int n = weight.size();

    vector<vector<float>> items(n, vector<float>(3));
    for (int i = 0; i < n; i++) {
        items[i][0] = weight[i];
        items[i][1] = profit[i];
        items[i][2] = profit[i] / weight[i];
    }

    sort(items.begin(), items.end(), [](auto &a, auto &b) {
        return a[2] > b[2];
    });

    float totalProfit = 0, totalWeight = 0;

    for (int i = 0; i < n; i++) {
        if (totalWeight + items[i][0] <= cap) {
            totalWeight += items[i][0];
            totalProfit += items[i][1];
            cout << "(" << items[i][0] << ", " << items[i][1] << ", 1.00)\n";
        } else {
            float remain = cap - totalWeight;
            float fraction = remain / items[i][0];
            totalProfit += items[i][1] * fraction;
            totalWeight += remain;
            cout << "(" << items[i][0] << ", " << items[i][1] << ", " << fraction << ")\n";
            break;
        }
    }

    cout << "Total Profit = " << totalProfit << "\n";
}


int main() {
    int n = 5;
    float cap = 60;

    vector<float> weight = {5, 10, 15, 22, 25};
    vector<float> profit = {30, 40, 45, 77, 90};

    cout << "\n Greedy by Profit: \n";
    greedyByProfit(weight, profit, cap);
    cout << "\n Greedy by Weight: \n";
    greedyByWeight(weight, profit, cap);
    cout << "\n Greedy by Profit/Weight ratio: \n";
    greedyByBoth(weight, profit, cap);
}