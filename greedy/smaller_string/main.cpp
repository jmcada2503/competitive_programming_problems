#include <bits/stdc++.h>

#define debug(n) cout << n << endl
#define endl '\n'

typedef long long ll;
typedef long l;

using namespace std;

void update_list(vector<int> &s, string &x, int k) {
    for (int i=0; i<x.size(); i++) {
        s[int(x[i])-97] += k;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int cases; cin >> cases;
    while (cases--) {
        int n; cin >> n;
        vector<int> s = vector<int>(30, 0);
        s[0] = 1;
        vector<int> t = vector<int>(30, 0);
        t[0] = 1;

        int c, k;
        string x;
        while (n--) {
            cin >> c >> k >> x;
            if (c == 1) {
                update_list(s, x, k);
            }
            else if (c == 2) {
                update_list(t, x, k);
            }

            bool ans = false;
            for (int i=29; i>=0; i--) {
                if (s[i] < t[i]) {
                    cout << "YES" << endl;
                    ans = true;
                    break;
                }
                else if (s[i] > t[i]) {
                    cout << "NO" << endl;
                    ans = true;
                    break;
                }
            }

            if (!ans) {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}
