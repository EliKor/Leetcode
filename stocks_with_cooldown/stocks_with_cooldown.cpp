#include <iostream>
#include <string>
#include <vector>

using namespace std;

int max_profit_slow(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> opt(n, vector<int>(n, 0));
    vector<int> max_prev(n, 0);
    int max_prof = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            opt[i][j] = prices[j] - prices[i];
            opt[i][j] += i-2 >= 0 ? max_prev[i-2] : 0;
            if (j-1 >= 0) {
                max_prev[j] = max(max_prev[j], max_prev[j-1]);
            }
            max_prof = max(max_prof, opt[i][j]);
            max_prev[j] = max(max_prev[j], opt[i][j]);
        }
    }
    return max_prof;
}

int max_profit(vector<int>& prices) {
    int n = prices.size();
    if (n < 2) {
        return 0;
    }
    int buy_prev = -prices[0];
    int sell_prev = 0, sell_prev_prev = 0;
    for (int i = 1; i < prices.size(); i++) {
        int buy = max(buy_prev, sell_prev_prev - prices[i]);
        int sell = max(sell_prev, buy_prev + prices[i]);
        sell_prev_prev = sell_prev;
        sell_prev = sell;
        buy_prev = buy;
    }
    return sell_prev;
}

int main() {
    vector<int> test { 1, 2, 3, 0, 2 };
    int max_prof = max_profit_dc(test);
    cout << "max profit: " << max_prof << endl;
    return 0;
}
