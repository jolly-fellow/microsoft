#include <iostream>
#include <vector>
#include <climits>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int solution(const vector<int> &A, const vector<int> &B, int N) {
    int roads_num = A.size(); // M
    vector<int> cities(N + 1, 0);
    // count number of roads to the pair of cities
    for (int i = 0; i < roads_num; ++i) {
        cities[A[i]]++;
        cities[B[i]]++;
    }
    int result = INT_MIN;
    // Find maximum number of roads connected to the pair
    // of cities except the road between these two cities
    // because it was counted twice for each city.
    for (int i = 0; i < roads_num; ++i) {
        result = max(result, cities[A[i]] + cities[B[i]] - 1);
    }
    return result;
}


int main() {

    vector<int> a = { 1, 2, 3, 4, 5, 6, 3, 12, 11, 10, 9 };
    vector<int> b = { 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8};
    int n = 11;


    cout << "Result: " << solution({1, 2, 3, 3},{2, 3, 1, 4}, 4) << " expected: 4" << endl;

    cout << "Result: " << solution(a,b, 12) << " expected: 7" << endl;

    return 0;
}

