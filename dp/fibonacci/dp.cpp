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

long long fibonacci(int n, vector<long long> &dp) {
    if (dp[n] > -1)
        return dp[n];
    dp[n] = (fibonacci(n-1, dp)+fibonacci(n-2, dp));
    return dp[n];
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);

    // 0 1 1 2 3 5 8 13 21

    int n;
    cin >> n;

    vector<long long> dp(n+1, -1);
    dp[0] = 0;
    dp[1] = 1;

    cout << "fibonacci: " << fibonacci(n, dp) << endl;

    return 0;
}
