#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int trapped_water_stack(vector<int>& heights) {
    stack<int> st;
    int trapped = 0;
    for (int i = 0; i < heights.size(); i++) {
        while (!st.empty() && heights[i] > heights[st.top()]) {
            int top = st.top();
            st.pop();
            if (st.empty()) {
                break;
            }
            int bounding_height = min(heights[i], heights[st.top()]) - heights[top];
            int dist = i - st.top() - 1;
            trapped += bounding_height * dist;
        }
        st.push(i);
    }
    return trapped;
}
            


int trapped_water(vector<int>& heights) {
    int trapped = 0;
    int left = 0, left_max = 0;
    int right = heights.size() - 1, right_max = 0;
    while (left < right) {
        if (heights[left] < heights[right]) {
            if (heights[left] >= left_max) {
                left_max = heights[left];
            }
            else {
                trapped += left_max - heights[left];
            }
            left++;
        }
        else {
            if (heights[right] >= right_max) {
                right_max = heights[right];
            }
            else {
                trapped += right_max - heights[right];
            }
            right--;
        }
    }
    return trapped;
}


int main() {
    pair<vector<int>, int> test0 {{0,1,0,2,1,0,1,3,2,1,2,1}, 6};
    pair<vector<int>, int> test1 {{4,2,0,3,2,5}, 9};
    vector<pair<vector<int>, int>> tests { test0, test1 };
    for (int i = 0; i < tests.size(); i++) {
        if (trapped_water_stack(tests[i].first) != tests[i].second) {
            cout << "Test " << i << " failed" << endl;
        }
        else {
            cout << "Test " << i << " passed" << endl;
        }
    }
    return 0;
}
