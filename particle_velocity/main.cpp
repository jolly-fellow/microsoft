#include <iostream>
#include <vector>

using namespace std;

int solution(const vector<int> & v) {
    int total_periods = 0, v_size = v.size();
    for (int i = 0; i < v_size; i++) {
        for (int count = 0; i + 2 < v_size && v[i + 1] - v[i] == v[i + 2] - v[i + 1]; i++) {
            total_periods += ++count;
        }
    }
    return total_periods < 1000000000 ? total_periods : -1;
}

int main() {
    vector<int> input = {-1,1,3,3,3,2,3,2,1,0};
    cout << solution(input) << " Expected: 5" << endl;

    return 0;
}

