#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int FindMaxSum(std::vector<int> v) {
    int v_size = v.size();
    unordered_set<int> m;
    int max_sum = 0;
    m.reserve(v_size*v_size); // to prevent rehashes

    // Traverse through all possible pairs of v
    for (int i = 0; i < v_size; ++i) {
        for (int j = i + 1; j < v_size; ++j) {
            // If sum of current pair is not in hash,
            // then store it and continue to next pair
            int sum = v[i] + v[j];
            if (m.count(sum)) {
                if(max_sum < sum) {
                    max_sum = sum;
                }
            }
            else {
                m.emplace(sum);
            }
        }
    }
    return (max_sum > 0) ? max_sum : -1;
}

int main() {

    cout << FindMaxSum({ 25, 4, 28, 1, 5, 1, 17, 2 }) << " Expected: 30";

    return 0;
}

