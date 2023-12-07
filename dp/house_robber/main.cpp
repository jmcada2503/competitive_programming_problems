#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <deque>
#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

long long int houseRobber(vector<int>& valueInHouse)
{
    long long int prev_2 = 0, prev_1 = valueInHouse[valueInHouse.size()-2];
    for (int i=2; i<valueInHouse.size(); i++) {
        long long int pick = valueInHouse[valueInHouse.size()-1-i]+prev_2;
        long long int not_pick = prev_1;
        prev_2 = prev_1;
        prev_1 = max(pick, not_pick);
    }
    long long int ans = max(prev_1, prev_2);

    prev_2 = 0, prev_1 = valueInHouse[valueInHouse.size()-1];
    for (int i=1; i<valueInHouse.size()-1; i++) {
        long long int pick = valueInHouse[valueInHouse.size()-1-i]+prev_2;
        long long int not_pick = prev_1;
        prev_2 = prev_1;
        prev_1 = max(pick, not_pick);
    }
    return max(max(prev_1, prev_2), ans);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int cases; cin >> cases;
    while (cases--) {
        int n; cin >> n;

        vector<int> nums;
        nums.reserve(n);

        int e;
        for (int i=0; i<n; i++) {
            cin >> e;
            nums.push_back(e);
        }

        cout << houseRobber(nums) << endl;
    }

    return 0;
}
