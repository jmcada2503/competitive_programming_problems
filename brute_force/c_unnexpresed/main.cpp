#include <bits/stdc++.h>

#define debug(n) cout << n << endl
#define endl '\n'

typedef long long ll;
typedef long l;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    ll n;
    cin >> n;

    cout << n-(distance(numbers.begin(), lower_bound(numbers.begin(), numbers.end(), n))+1) << endl;

    return 0;
}