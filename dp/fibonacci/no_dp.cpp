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

long long fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n-1)+fibonacci(n-2);
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    cout << "fibonacci: " << fibonacci(n) << endl;

    return 0;
}
