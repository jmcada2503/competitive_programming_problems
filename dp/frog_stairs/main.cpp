#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <deque>

#define endl '\n'

using namespace std;

int min_energy(int position, vector<int> &stairs, unordered_map<int,int> &dp) {
    if (position == stairs.size()-1) {
        return 0;
    }
    else {
        auto dp_ans = dp.find(position);
        if (dp_ans != dp.end()) {
            return dp_ans->second;
        }
        else {
            int ans;
            if (position == stairs.size()-2) {
                ans = abs(stairs[position]-stairs[position+1])+min_energy(position+1, stairs, dp);
                dp[position] = ans;
                return ans;
            }
            else {
                ans = min(abs(stairs[position]-stairs[position+1])+min_energy(position+1, stairs, dp), abs(stairs[position]-stairs[position+2])+min_energy(position+2, stairs, dp));
                dp[position] = ans;
                return ans;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int cases; cin >> cases;
    while (cases--) {
        int n, e; cin >> n;
        vector<int> stairs;
        stairs.reserve(n);
        unordered_map<int,int> dp;

        for (int i=0; i<n; i++) {
            cin >> e;
            stairs.push_back(e);
        }

        cout << min_energy(0, stairs, dp) << endl;
    }

    return 0;
}
