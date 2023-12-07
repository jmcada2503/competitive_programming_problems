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

int jump_recursively(int position, vector<int> &nums, vector<int> &dp) {
    if (position >= (nums.size()-1)) {
        return 0;
    }
    else if (nums[position] == 0) {
        return nums.size();
    }

    if (dp[position] != -1) {
        return dp[position];
    }
    long min = -1;
    for (int i=1; i<=nums[position]; i++) {
        long value = jump_recursively(position+i, nums, dp);
        if (min == -1) {
            min = value;
        }
        else if (value < min) {
            min = value;
        }
    }
    dp[position] = min+1;
    return min+1;
}

class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp = vector<int>(nums.size(), -1);
        return jump_recursively(0, nums, dp);
    }
};

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);

    vector<int> nums = {3,2,1,1,9,1,1,1,1,1,1,1,1,1};
    Solution solution;
    cout << solution.jump(nums) << endl;

    return 0;
}
