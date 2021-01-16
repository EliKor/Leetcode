#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = matrix.size();
        if (m < 1)
            return false;
        int n = matrix[0].size();
        int row = 0, col = n - 1;
        while (col >= 0 && row < m) {
            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] > target)
                col--;
            else
                row++;
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix{
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}};
    cout << std::boolalpha;
    cout << "Searching for 0 in nums yields: " << sol.searchMatrix(matrix, 0) << "\n";
    cout << "Searching for 5 in nums yields: " << sol.searchMatrix(matrix, 5) << "\n";
    return 0;
}
