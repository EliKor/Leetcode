#include <iostream>
#include <string>
#include <vector>

using namespace std;

int merge(vector<int>& nums, int lo, int mid, int hi) {
    int left_max = INT_MIN;
    int left_min = INT_MAX;
    int curr = 1;
    for (int i = mid; i >= lo; i--) {
        curr *= nums[i];
        left_max = max(left_max, curr);
        left_min = min(left_min, curr);
    }
    int right_max = INT_MIN;
    int right_min = INT_MAX;
    curr = 1;
    for (int i = mid+1; i <= hi; i++) {
        curr *= nums[i];
        right_max = max(right_max, curr);
        right_min = min(right_min, curr);
    }
    int mult_max = max(left_max * right_max, left_min * right_min);
    return max(mult_max, max(left_max, right_max));
}

int max_product_helper(vector<int>& nums, int lo, int hi) {
    if (lo == hi) {
        return nums[lo];
    }
    int mid = lo + (hi-lo)/2;
    int left_max = max_product_helper(nums, 0, mid);
    int right_max = max_product_helper(nums, mid+1, hi);
    int merged_max = merge(nums, lo, mid, hi);
    return max(merged_max, max(left_max, right_max));
}

int max_product_subarray_dc(vector<int>& nums) {
    return max_product_helper(nums, 0, nums.size()-1);
}

int max_product_subarray(vector<int>& nums) {
    int right_prefix = 0;
    int left_prefix = 0;
    int max_prod = INT_MIN;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        right_prefix = nums[n-i-1] * (right_prefix == 0 ? 1 : right_prefix);
        left_prefix = nums[i] * (left_prefix == 0 ? 1 : left_prefix);
        max_prod = max(max_prod, max(left_prefix, right_prefix));
    }
    return max_prod;
}

int main() {
    pair<vector<int>, int> test0 {{ 0, 0, 0 }, 0};
    pair<vector<int>, int> test1 {{ -2 }, -2};
    pair<vector<int>, int> test2 {{ -2, 0, 3 }, 3};
    pair<vector<int>, int> test3 {{ -2, 4, -1, -12, 3 }, 144};
    vector<pair<vector<int>, int>> tests { test0, test1, test2, test3 }; 
    for (int i = 0; i < tests.size(); i++) {
        if (max_product_subarray(tests[i].first) != tests[i].second) {
            cout << "Test " << i << " failed" << endl;
        }
        else if (max_product_subarray_dc(tests[i].first) != tests[i].second) {
            cout << "Test " << i << " failed" << endl;
        }
        else {
            cout << "Test " << i << " passed" << endl;
        }
    }
    return 0;
}
