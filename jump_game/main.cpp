#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

unordered_set<int> vis;
bool solution(const vector<int>& arr, int st) {
    if (st >= 0 && st < arr.size() && vis.insert(st).second) {
        return arr[st] == 0 ||
                solution(arr, st + arr[st]) || solution(arr, st - arr[st]);
    }
    return false;
}

int main() {

    cout << "Result: " << solution({3, 4, 2, 3, 0, 3, 1, 2, 1}, 7) << " Expected: true" << endl;

    return 0;
}

