#include <bits/stdc++.h>

#define debug(n) cout << n << endl
#define endl '\n'

typedef long long ll;
typedef long l;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll maximum;
    cin >> maximum;

    unordered_set<ll> numbers_set;

    for (int a=2; pow(a,2)<=maximum; a++) {
        for (int b=2; pow(a,b) <= maximum; b++) {
            numbers_set.insert(pow(a,b));
        }
    }

    cout << maximum-numbers_set.size() << endl;

    return 0;
}
