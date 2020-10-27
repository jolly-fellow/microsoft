#include <iostream>
#include <vector>

using namespace std;

// v.size() caps at 100,000, so largest answer possible for
// this is 100,000
// values in array is from 1....100,000,000

int solution(const vector<int> &v) {
    const int MAX_RESULT = 100000;
    int result = 0;

    int max_value = 0;

    int array[MAX_RESULT + 1] = {};

    for (int x : v) {
        if (x > MAX_RESULT)
            continue;

        array[x]++;
        max_value = max(max_value, x);
    }

    for (int i = 0; i <= max_value; i++) {
        if (i == array[i]) {
            result = max(i, result);
        }
    }
    return result;
}

int main() {

    cout << solution({3, 8, 2, 3, 3, 2}) << " Expected: 3" << endl;
    cout << solution({7, 1, 2, 8, 2}) << " Expected: 2" << endl;
    cout << solution({3, 1, 4, 1, 5}) << " Expected: 0" << endl;
    cout << solution({5, 5, 5, 5, 5}) << " Expected: 5" << endl;

    return 0;
}

