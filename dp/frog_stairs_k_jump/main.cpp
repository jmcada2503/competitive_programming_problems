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

int min_energy(int position, int k, vector<int> &stairs, unordered_map<int,int> &dp) {
    if (position == stairs.size()-1) {
        return 0;
    }
    else {
        auto dp_ans = dp.find(position);
        if (dp_ans != dp.end()) {
            return dp_ans->second;
        }
        else {
            int ans, posible_ans;
            ans = abs(stairs[position]-stairs[position+1])+min_energy(position+1, k, stairs, dp);
            for (int i=2; i<=min((int(stairs.size())-position)-1, k); i++) {
                posible_ans = abs(stairs[position]-stairs[position+i])+min_energy(position+i, k, stairs, dp);
                if (posible_ans < ans) {
                    ans = posible_ans;
                }
            }
            dp[position] = ans;
            return ans;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k; cin >> n; cin >> k;

    vector<int> stairs;
    stairs.reserve(n);
    unordered_map<int,int> dp;

    int e;
    for (int i=0; i<n; i++) {
        cin >> e;
        stairs.push_back(e);
    }

    cout << min_energy(0, k, stairs, dp) << endl;

    return 0;
}
