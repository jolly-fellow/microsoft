#include <iostream>
#include <vector>

using namespace std;

int solution(const vector<int> & a, const vector<int> & b) {
    long res = 0, sum_a = 0, sum_b = 0, a_size = a.size();
    for(int i=0; i < a_size; ++i) {
        sum_a += a[i];
        sum_b += b[i];
    }

    // if total sum of arrays are not equal or not even, then can't divide
    if (sum_a != sum_b || sum_a % 2 != 0 || sum_b % 2 != 0) { return 0; }

    int tmp_a = 0, tmp_b = 0;
    for(int i=0; i < a_size - 1; ++i) {
        tmp_a += a[i];
        tmp_b += b[i];
        // Only need to check either sum_a or sum_b is twice of tmp_a or tmp_b
        if(sum_a == 2 * tmp_a && tmp_a == tmp_b) { res++; }
    }
    return res;
}

int main() {
    vector<int> A1 = {4,-1,0,3}, B1 = {-2, 5, 0 ,3};
    vector<int> A2 = {2,-2,-3,3}, B2 = {0,0,4,-4};
    vector<int> A3 = {4,-1,0,3}, B3 = {-2,6,0,4};
    vector<int> A4 = {3,2,6}, B4 = {4,1,6};
    vector<int> A5 = {1,4,2,-2,5}, B5 = {7,-2,-2,2,5};

    cout << solution(A1, B1) << " Expected: 2" << endl;
    cout << solution(A2, B2) << " Expected: 1" << endl;
    cout << solution(A3, B3) << " Expected: 0" << endl;
    cout << solution(A4, B4) << " Expected: 0" << endl;
    cout << solution(A5, B5) << " Expected: 2" << endl;

    return 0;
}

