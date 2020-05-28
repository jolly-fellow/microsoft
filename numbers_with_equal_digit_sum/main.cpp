#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// this function returns sum of digits of a given number
int dsum(int a) {
    int s = 0;
    for (; a > 0; a /= 10) {
        s += a % 10;
    }
    return s;
}

int solution(const vector<int> & v) {
    using sum_t = int;
    using number_t = int;
    unordered_map<sum_t, number_t> m;
    // Maximum sum of given numbers
    int max_sum = 0;
    for (auto i : v) {
        int s = dsum(i);
        // If we have no such sum of digits in the map
        if (!m.count(s)) {
            // add this sum to the map as a key and the number as a value
            m[s] = i;
        }
        else {
            // if we have the sum of digits in the map
            // if sum of current number and number from the map with the same sum of digits are bigger than
            // maximum encountered sum then update the maximum sum
            max_sum = max(max_sum, m[s] + i);
            // Save current number as value for current sum of digits if it is bigger than number from the map
            m[s] = max(i, m[s]);
        }
    }
    // if the are no numbers with equal sum return -1
    return max_sum ? max_sum : -1;
}

int main() {

    cout << "Result: " << solution({51, 32, 43}) << " expected -1" << endl;
    cout << "Result: " << solution({42, 33, 60}) << " expected 102" << endl;
    cout << "Result: " << solution({51, 71, 17, 42}) << " expected 93" << endl;

    return 0;
}

