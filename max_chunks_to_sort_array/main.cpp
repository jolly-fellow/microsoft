#include <iostream>
#include <vector>

using namespace std;

void print(const vector<int> v) {
    for(auto i: v) {
        cout << i << ", ";
    }
    cout << endl;
}

/*
 For the task where the given array is a permutation without gaps the solution is easier
 Like in the task https://leetcode.com/problems/max-chunks-to-make-sorted
 We need to divide the array to two parts and check that any value on the left part is lower than
 the value on the border between the part in the sorted array.

 We know that the array is a permutation without gaps. It meant that if we sort this arrays
 values if it's items will be the same as their indices. So in order to check if current value in an item is lower
 or equal to the value in a sorted array we just need to compare this value with it's index. In case of the permutation
 if the value is greater than it's index it means we can not make division of the array here but if it is equal -
 we can.

Example:
 sorted array [0,1,2,3,4,5]
 permuted array which is given to us [0,3,1,2,5,4]

 divided array [(0),3,1,2,5,4] - 0 is equal to it's index so we CAN divide the array here.

 divided array [0,(3),1,2,5,4] - 3 is greater than it's index = 1 where 1 is a value which must be here in a sorted array
 so we can NOT divide the array here.

 we check the same all other items which are not equal to their indices until 5.

 divided array [0,3,1,2,(5),4] - 5 is equal to it's index so we CAN divide the array here.

 */

int solution1(vector<int> v) {
    int v_size = v.size();
    int count = 0, max_value = 0;
    for (int i = 0; i < v_size; i++) {
        max_value = std::max(max_value, v[i]);
        cout << max_value << ", ";
        if (max_value == i) {
            count++;
        }
    }
    cout << endl;
    return count;
}

/*
 In case of the question from Microsoft
 https://leetcode.com/discuss/interview-question/524146/
 we have an array which items are not guaranteed to be in range [0, size_of_array - 1].
 And they may have gaps.
 For this case we should use inverted algorithm - move from the back to the front of the array,
 track the minimum value and check if the array item is lower. Track the minimum processed value.
 If we meet a value lower than the minimum we should add one split point and set the current value as the minimum.
 Because in process of sorting we should not swap current current value and minimum value it means they are already
 in ascending order so we can split the array here.
 */
int solution2(const vector<int> v) {
    int v_size = v.size();
    int count = 1, min_value = v[v_size - 1];

    int current = v[v_size - 1];
    for (int i = v_size - 2; i >= 0; --i) {
        current = std::min(v[i], current);
        if (current < min_value) {
            ++count;
            min_value = current;
        }
    }
    return count;
}


int main() {
    cout << solution2({2,4,1,6,5,9,7}) << " Expected: 3" << endl;
    cout << solution2({4,3,2,6,1}) << " Expected: 1" << endl;
    cout << solution2({2,1,6,4,3,7}) << " Expected: 3" << endl;
    cout << solution1({0,3,1,2,5,4}) << " Expected: 3" << endl;

    return 0;
}

