#include <iostream>
#include <string>
#include <vector>

using namespace std;

int knapsack_0_1(vector<int> weights, vector<int> values, int W) {
    vector<int> opt(W+1, 0);
    for (int i = 0; i < weights.size(); i++) {
        for (int j = W; j >= weights[i]; j--) {
            opt[j] = max(opt[j], opt[j-weights[i]] + values[i]);
        }
    }
    return opt[W];
}

int knapsack(vector<int> weights, vector<int> values, int W) {
    vector<int> opt(W+1, 0);
    for (int i = 0; i <= W; i++) {
        int max_val = 0;
        for (int j = 0; j < weights.size(); j++) {
            if (weights[j] <= i) {
                max_val = max(max_val, opt[i-weights[j]] + values[j]);
            }
        }
        opt[i] = max_val;
    }
    return opt[W];
}

int main() {
    vector<int> values {7, 8, 4};
    vector<int> weights {3, 8, 6};
    int W = 10;
    cout << knapsack_0_1(weights, values, W) << endl;
    return 0;
}
