#include <iostream>
#include <vector>

using namespace std;

/*
Simple idea
n = 1, [0]
n = 2, [-1, 1]

Now write more based on this
n = 3, [-2, 0, 2]
n = 4, [-3, -1, 1, 3]
n = 5, [-4, -2, 0, 2, 4]

*/

vector<int> sumZero1(int n) {
    vector<int> v;
    v.reserve(n);
    int until = n/2;
    // if n is odd
    if (n & 1) { v.push_back(0); }
    for (int i = 1; i <= until; ++i) { v.push_back(i); v.push_back(-i); }
    return v;
}

/*
Another idea based on properties of the sequence
Find the rule
A[i] = i * 2 - n + 1

Math Observation

Actually, this rule could be derived from constructing an arithmetic sequence.
(Note that any arithmetic sequence must have unique values if the common delta is non-zero)
We need the sequence sum, so that

(a[0] + a[n-1]) * n / 2 = 0, which means a[0] + a[n-1] = 0.

Note that a[n-1] - a[0] = (n-1) * delta, which is -2 * a[0],
so we simply set delta = 2, a[0] = 1 - n
*/

vector<int> sumZero2(int n) {
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = i * 2 - n + 1;
    }
    return v;
}

int main() {

    cout << "" << endl;

    return 0;
}

