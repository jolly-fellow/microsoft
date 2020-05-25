#include <iostream>
#include <vector>

using namespace std;


int solution(vector<int>& v, int m) {
    if (m <= 1) { return v.size(); }

    vector<int> m_subset(m, 0);

    int max_count = 0;

    for (auto i : v) {
        int index = (i < 0) ? ((i % m) + m) % m  : i % m;
        max_count = max(++m_subset[index], max_count);
    }
    return (max_count < 2) ? 0 : max_count;
}


int main() {
    vector<int> v1 = {-3, -2, 1, 0, 8, 7, 1};
    cout << solution(v1, 3) << endl;

    vector<int> v2 = {7, 2, 4, 8, 6};
    cout << solution(v2, 2) << endl;

    vector<int> v3 = {3, 1, 4, 1, 5};
    cout << solution(v3, 1) << endl;

    vector<int> v4 = {5, 5, 5, 5, 5};
    cout << solution(v4, 0) << endl;

    vector<int> v5 = {4, 7, 10, 6, 9};
    cout << solution(v5, 3) << endl;

    return 0;
}