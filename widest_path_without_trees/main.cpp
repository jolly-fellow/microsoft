#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
Approach:

Since we have to find the vertical path, we can focus only in the x co-ordinates, i.e., values of v array
Now, we have to find the max width between the values in v array.
We can sort the v array and find the maximal difference between the adjacent elements.

For example:

int v = {5, 5, 5, 7, 7, 7}
int res = 0;

res = max( res, (v[1] - v[0]) ) ==> max(0, (5-5)), then res is 0
res = max( res, (v[2] - v[1]) ) ==> max(0, (5-5)), then res is 0
res = max( res, (v[3] - v[2]) ) ==> max(0, (7-5)), then res is 2
res = max( res, (v[4] - v[3]) ) ==> max(2, (7-7)), then res is 2
res = max( res, (v[5] - v[4]) ) ==> max(2, (7-7)), then res is 2

So, max width is 2
*/

int solution (vector<int> & v) {
    int res = 0;
    int v_size = v.size();

    sort(v.begin(), v.end());

    for (int i = 0; i < v_size-1; ++i) {
        res = max(res, (v[i+1] - v[i]));
    }
    return res;
}

int main() {

    vector<int> v = {5,5,5,7,7,7};
    
    cout << solution(v) << " Expected: 2" << endl;

    return 0;
}

