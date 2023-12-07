#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <deque>

#define debug(n) cout << n << endl
#define endl '\n'

using namespace std;

long long get_minimum_cost(vector<long long> &l, vector<long long> &r) {
    if (l[0] == r[0] && l[1] == r[1]) {
        return min(l[2], r[2]);
    }
    else if ((l[0] == r[0] && l[1] > r[1]) || (l[0] < r[0] && l[1] == r[1]) || (l[0] < r[0] && l[1] > r[1])) {
        return l[2];
    }
    else if ((l[0] == r[0] && r[1] > l[1]) || (r[0] < l[0] && l[1] == r[1]) || (r[0] < l[0] && r[1] > l[1])) {
        return r[2];
    }
    else {
        return l[2] + r[2];
    }
}

long long simulate(vector<long long> &l, vector<long long> &r) {
    return r[1]-l[0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int c; cin >> c;
    while (c--) {

        long n; cin >> n;
        vector<long long> l, r, m;
        l.reserve(3);
        r.reserve(3);
        m.reserve(3);
        long long e;
        for (int i=0; i<3; i++) {
            cin >> e;
            l.push_back(e);
            r.push_back(e);
            m.push_back(e);
        }
        cout << l[2] << endl;

        vector<long long> aux = vector<long long>(3, 0ll);
        for (long i=1; i<n; i++) {
            cin >> aux[0] >> aux[1] >> aux[2];
            long long s = simulate(l,r);
            if (aux[0] < l[0] || (aux[0] == l[0] && aux[2] < l[2])) {
                l = aux;
            }
            if (aux[1] > r[1] || (aux[1] == r[1] && aux[2] < r[2])) {
                r = aux;
            }
            if (simulate(l, r) > simulate(m, m)) {
                m[0] = l[0];
                m[1] = r[1];
                m[2] = get_minimum_cost(l, r);
            }

            cout << "l: "; for (auto i : l) cout << i << ' '; cout << endl;
            cout << "r: "; for (auto i : r) cout << i << ' '; cout << endl;
            cout << min(m[2], get_minimum_cost(l, r)) << endl;
        }

    }

    return 0;
}
