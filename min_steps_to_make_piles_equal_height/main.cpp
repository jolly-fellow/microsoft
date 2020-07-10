#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int solution(const vector<int> & v) {
    int v_size = v.size();
    int dif = unordered_set(v.begin(), v.end()).size();
    return v_size == dif ? dif : (v_size-1) * (dif-1);
}

int main() {

    cout << solution({5,2,1}) << " Expected: 3" << endl;
    cout << solution({5,5,1}) << " Expected: 2" << endl;
    cout << solution({5,5,5,5,1}) << " Expected: 4" << endl;

    return 0;
}

