#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <deque>
#include <cmath>

#define ll long long int
#define l long int
#define debug(n) cout << n << endl
#define endl '\n'

using namespace std;


vector<string> backtracking(int pos, string &digits, vector<string> &keyboard) {
    if (pos == digits.size()) {
        vector<string> base;
        base.push_back("");
        return base;
    }
    int d = stoi(digits.substr(pos,1));
    vector<string> exploration = backtracking(pos+1, digits, keyboard);

    vector<string> ans;
    for (int i=0; i<keyboard[d-2].size(); i++) {
        for (int j=0; j<exploration.size(); j++) {
            ans.push_back(keyboard[d-2][i]+exploration[j]);
        }
    }
    return ans;
}

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> keyboard = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        return digits.size() ? backtracking(0, digits, keyboard) : *(new vector<string>());
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solution my_solution;
    vector<string> ans = my_solution.letterCombinations("2");
    for (auto i : ans) cout << i << ' '; cout << endl;

    return 0;
}
