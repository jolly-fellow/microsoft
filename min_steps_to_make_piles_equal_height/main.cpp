#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int solution(const vector<int> & v) {
    return unordered_set(v.begin(), v.end()).size();
}

int main() {

    cout << solution({5,2,1}) << " Expected: 3" << endl;

    return 0;
}

