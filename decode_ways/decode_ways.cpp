#include <iostream>
#include <string>
#include <vector>

using namespace std;

int num_ways(string& s) {
    int n = s.size();
    vector<int> opt(n+1, 0);
    opt[0] = s[0] != '0';
    opt[1] = opt[0];
    for (int i = 2; i <= n; i++) {
        opt[i] = s[i-1] != '0' ? opt[i-1] : 0;
        if (s[i-2] > '0' && (s[i-2] < '2' || (s[i-2] == '2' && s[i-1] <= '6'))) {
            opt[i] += opt[i-2];
        }
    }
    return opt[n];
}

int main() {
    vector<pair<string, int>> tests { {"12", 2}, {"226", 3}, {"10", 1}, {"100", 0} };
    for (int i = 0; i < tests.size(); i++) {
        if (num_ways(tests[i].first) != tests[i].second) {
            cout << "Test " << i << " failed" << endl;
        }
        else {
            cout << "Test " << i << " passed" << endl;
        }
    }
    return 0;
}
