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

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);

    map<int,int> test;
    test[1] = 0;
    test[2] = 1;
    test[3] = -1;
    test[4] = 2;

    cout << test.begin()->first << endl;
    test[0] = 100;
    cout << test.begin()->first << endl;

    return 0;
}
