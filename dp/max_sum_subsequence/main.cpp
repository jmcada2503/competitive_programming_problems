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

int recursive_maximum_non_adjacent_sum(int position, vector<int> &nums, vector<int> &dp) {
    if (position+2 >= nums.size()) {
        return nums[position];
    }
    else if (dp[position] != -1) {
        return dp[position];
    }
    int ans = recursive_maximum_non_adjacent_sum(position+2, nums, dp);
    int posible_ans;
    for (int i=position+3; i<nums.size(); i++) {
        posible_ans = recursive_maximum_non_adjacent_sum(i, nums, dp);
        if (posible_ans > ans) {
            ans = posible_ans;
        }
    }
    dp[position] = nums[position]+ans;
    return dp[position];
}

int maximumNonAdjacentSum(vector<int> &nums){
    vector<int> dp = vector<int>(nums.size(), -1);

    int ans = recursive_maximum_non_adjacent_sum(0, nums, dp);
    int posible_ans;
    for (int i=1; i<nums.size(); i++) {
        posible_ans = recursive_maximum_non_adjacent_sum(i, nums, dp);
        if (posible_ans > ans) {
            ans = posible_ans;
        }
    }
    return ans;
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
