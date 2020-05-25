#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
/*
int dsum(int a) {
    int s = 0;
    while (a > 0) {
        s += a % 10;
        a = a / 10;
    }
    return s;
}
*/

int dsum(int a) {
    int s = 0;
    for (; a > 0; a /= 10) {
        s += a % 10;
    }
    return s;
}

int solution(const vector<int> & A) {
    unordered_map<int, int> m;
    int ans = 0;
    for (auto a : A) {
        int s = dsum(a);
        if (!m.count(s)) {
            m[s] = a;
        }
        else {
            ans = max(ans, m[s] + a);
            m[s] = max(a, m[s]);
        }
    }
    return ans ? ans : -1;
}

int main() {

    cout << "Result: " << solution({51, 32, 43}) << " expected -1" << endl;
    cout << "Result: " << solution({42, 33, 60}) << " expected 102" << endl;
    cout << "Result: " << solution({51, 71, 17, 42}) << " expected 93" << endl;

    return 0;
}

