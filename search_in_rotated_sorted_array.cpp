#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() < 1) return -1;
        int lo = 0;
        int hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                if (nums[lo] > nums[mid] && target > nums[hi]) {
                    hi = mid-1;
                }
                else {
                    lo = mid+1;
                }
            }
            else if (nums[mid] > target) {
                if (nums[hi] < nums[mid] && target < nums[lo]) {
                    lo = mid+1;
                }
                else {
                    hi = mid-1;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums{5, 1, 2, 3, 4};
    cout << "Searching for 0 in nums yields: " << sol.search(nums, 0) << "\n";
    cout << "Searching for 5 in nums yields: " << sol.search(nums, 5) << "\n";
    return 0;
}
