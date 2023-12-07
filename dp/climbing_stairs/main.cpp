#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <deque>

#define endl '\n'
#define lli long long
#define li long

using namespace std;

lli recursion(int n, unordered_map<int,lli> &combinations) {
    if (combinations.find(n) != combinations.end())
        return combinations[n];
    combinations[n] = recursion(n-1, combinations)+recursion(n-2, combinations);
    return combinations[n];
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);

    unordered_map<int,lli> combinations;
    combinations[1] = 1ll;
    combinations[2] = 2ll;

    int tc; cin >> tc;
    while (tc--) {

        int n; cin >> n;
        cout << recursion(n, combinations) << endl;


    }

    return 0;
}
