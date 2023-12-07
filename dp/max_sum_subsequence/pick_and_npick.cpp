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

int maximumNonAdjacentSum(vector<int> &nums){
    int prev_2 = nums[nums.size()-1], prev_1 = max(nums[nums.size()-2], nums[nums.size()-1]);
    for (int i=2; i<nums.size(); i++) {
        int pick = nums[nums.size()-1-i]+prev_2;
        int not_pick = prev_1;
        prev_2 = prev_1;
        prev_1 = max(pick, not_pick);
    }
    return max(prev_1, prev_2);
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

        cout << maximumNonAdjacentSum(nums) << endl;
    }

    return 0;
}
