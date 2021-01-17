#include <iostream>
#include <string>
#include <vector>

using namespace std;

int max_coins(vector<int>& nums) {
    int n = nums.size();

    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    vector<vector<int>> ranges(n+2, vector<int>(n+2, 0));

    for (int len = 1; len <= n; len++) {
        for (int start = 1; (start-1) + len <= n; start++) {
            int end = start + len - 1;
            for (int last = start; last <= end; last++) {
                int pop_others = ranges[start][last-1] + ranges[last+1][end];
                int pop_last = nums[start-1] * nums[last] * nums[end+1];
                ranges[start][end] = max(ranges[start][end], pop_others + pop_last);
            }
        }
    }
    
    return ranges[1][n];
} 

int main() {
    pair<vector<int>, int> test0 {{3,1,5,8}, 167};
    pair<vector<int>, int> test1 {{1,5}, 10};
    vector<pair<vector<int>, int>> tests { test0, test1 };
    for (int i = 0; i < tests.size(); i++) {
        if (max_coins(tests[i].first) != tests[i].second) {
            cout << "Test " << i << " failed" << endl;
        }
        else {
            cout << "Test " << i << " passed" << endl;
        }
    }
    return 0;
}
