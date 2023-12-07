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

long long fibonacci_recursion(long long a, long long b, int n, int cont) {
    if (cont == n)
        return a+b;
    return fibonacci_recursion(b, a+b, n, cont+1);
}

long long fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci_recursion(0, 1, n, 2);
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    cout << "fibonacci(" << n << "): " << fibonacci(n) << endl;

    return 0;
}
