#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

bool word_break(string& s, vector<string>& wordDict) {
    int n = s.size();
    unordered_set<string> words(wordDict.begin(), wordDict.end());
    vector<bool> up_to(n+1, false);
    up_to[0] = true;
    for (int i = 0; i < n; i++) {
        for (int len = 1; i + len <= n; len++) {
            string sub = s.substr(i, len);
            if (words.find(sub) != words.end()) {
                up_to[i+len] = up_to[i+len] || up_to[i];
                if (up_to[n]) {
                    return true;
                }
            }
        }
    }
    return up_to[n];
}

vector<string> word_break_ii_helper(string& s, unordered_set<string>& words, unordered_map<string, vector<string>>& memo) {
    vector<string> res;
    if (s.size() == 0) {
        res = {""};
        return res;
    }
    if (memo.find(s) != memo.end()) {
        return memo[s];
    }
    for (int len = 1; len <= s.size(); len++) {
        string prefix = s.substr(0, len);
        if (words.find(prefix) != words.end()) {
            string suffix = s.substr(len);
            vector<string> sentences = word_break_ii_helper(suffix, words, memo);
            for (int i = 0; i < sentences.size(); i++) {
                if (sentences[i].size() == 0) {
                    res.push_back(prefix);
                }
                else {
                    res.push_back(prefix + " " + sentences[i]);
                }
            }
        }
    }
    memo[s] = res;
    return res;
}

vector<string> word_break_ii(string& s, vector<string>& wordDict) {
    unordered_set<string> words(wordDict.begin(), wordDict.end());
    unordered_map<string, vector<string>> memo;
    return word_break_ii_helper(s, words, memo);
}

int main() {
    pair<pair<string, vector<string>>, bool> test1, test2; 
    test1 = {{"leetcode", {"leet", "code"}}, true};
    test2 = {{"catsandog", {"cats", "dog", "sand", "and", "cat"}}, false};
    vector<pair<pair<string, vector<string>>, bool>> tests;
    tests = { test1, test2 };
    for (int i = 0; i < tests.size(); i++) {
        if (word_break(tests[i].first.first, tests[i].first.second) != tests[i].second) {
            cout << "Test " << i << " failed" << endl;
        }
        else {
            cout << "Test " << i << " passed" << endl;
        }
    }
    pair<pair<string, vector<string>>, vector<string>> testii1, testii2;
    testii1 = {{"catsanddog", {"cat", "cats", "and", "sand", "dog"}}, {"cat sand dog", "cats and dog"}};
    testii2 = {{"catsandog", {"cat", "dog", "sand", "and", "cat"}}, {}};
    vector<pair<pair<string, vector<string>>, vector<string>>> testsii;
    testsii = { testii1, testii2 };
    for (int i = 0; i < testsii.size(); i++) {
        if (word_break_ii(testsii[i].first.first, testsii[i].first.second) != testsii[i].second) {
            cout << "Testii " << i << " failed" << endl;
        }
        else {
            cout << "Testii " << i << " passed" << endl;
        }
    }
    return 0;
}
