#include <iostream>
#include <string>
#include <vector>

using namespace std;

string largest_number(vector<int>& nums) {
    vector<string> strings;
    for (auto& i : nums) {
        strings.push_back(to_string(i));
    }
    sort(strings.begin(), strings.end(), [](string& s1, string& s2) {
        string s1s2 = s1 + s2;
        string s2s1 = s2 + s1;
        return s1s2 > s2s1;
    });
    string res = "";
    for (auto& s : strings) {
        res += s;
    }
    if (res[0] == '0') {
        return "0";
    }
    return res;
}

int main() {
    pair<vector<int>, string> test0 {{3, 30, 34, 5, 9}, "9534330"};
    pair<vector<int>, string> test1 {{10, 2}, "210"};
    pair<vector<int>, string> test2 {{0, 0, 0}, "0"};
    pair<vector<int>, string> test3 {{8308, 8308, 830}, "83088308830"};
    vector<pair<vector<int>, string>> tests { test0, test1, test2, test3 };
    for (int i = 0; i < tests.size(); i++) {
        if (largest_number(tests[i].first) != tests[i].second) {
            cout << "Test " << i << " failed" << endl;
        }
        else {
            cout << "Test " << i << " passed" << endl;
        }
    }
    return 0;
}
