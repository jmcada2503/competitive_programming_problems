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

int f(int position, int past, vector<vector<int>> &points, vector<vector<int>> &dp) {
    // cout << "f(" << position << "): " << past << endl; 
    if (position == points.size()-1) {
        int max = 0;
        for (int i=0; i<3; i++) {
            if (points[position][i] > max && i != past) {
                max = points[position][i];
            }
        }
        return max;
    }
    if (dp[position][past] > 0) {
        // cout << "dp -> " << dp[position][past] << endl;
        return dp[position][past];
    }
    int max = 0;
    int possible_max = 0;
    for (int i=0; i<3; i++) {
        if (i != past) {
            int possible_max = points[position][i]+f(position+1, i, points, dp);
            if (possible_max > max) {
                max = possible_max;
            }
        }
    }
    dp[position][past] = max;
    // cout << "computed -> " << max << endl;
    return max;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp = vector<vector<int>>(n, vector<int>(3, 0));

    int max = 0;
    int possible_max = 0;
    for (int i=0; i<3; i++) {
        int possible_max = points[0][i]+f(1, i, points, dp);
        if (possible_max > max) {
            max = possible_max;
        }
    }
    return max;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int cases; cin >> cases;
    while (cases--) {
        int n; cin >> n;

        vector<vector<int>> points = vector<vector<int>>(n, vector<int>(3, 0));
        for (int i=0; i<n; i++) {
            cin >> points[i][0] >> points[i][1] >> points[i][2];
        }

        cout << ninjaTraining(n, points) << endl;
    }

    return 0;
}
