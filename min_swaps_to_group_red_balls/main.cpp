#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/* Description of the algorithm for similar task from Google
So we can solve this question by sliding window method. We always keep a window that contains k girls' position and
 process the string char by char. If we encounter a boy, we do nothing; otherwise we move the window to contain the
 current girl and pop out the left most girl.

To solve the minimum swaps needed in the current window, one can find the median position of k girls in the window
 and calculate the distances from the other girls to the girl in the median position. For example, consider string
 = "B[GGGBBBBG]BBGGBGG", the median position in the current window is 2 or 3 (indexed from 0). Let the median position
 be 2, the total distances from all the other girls is 1 + 1 + 6 = 8. Then you minus the fixed adjust distance
 (1 + 1 + 2) = 4 and get the minimum number of swaps = 4. The fixed adjust distance here is because you move all girls
 into the median position, but the girls are sitting in a consecutive row instead of the same position.

Therefore we already have a O(kn)-time O(k)-space algorithm, k is for the time to solve the minimum number of swaps
 in the current window and n is for the time to scan the whole string.

Of course you can improve the algorithm to be O(n) time. This is because when the window is sliding to the next one,
 the median position can be tracked easily if the window is implemented by a linked list. Regarding updating the
 distances to the median position, let the left_distance be the total distances from the girls to the left of the
 median girl and similarly for the right_distance. Let m be the median position and m' be the new median position.
 Consider the window slides to the next girl at position j and pops the most left girl at position i.
 The the new left_distance = left_distance - (m - i) + (m' - m) * ((k - 1) / 2)
 and the new right_distance = right_distance + (j - m') - (m' - m) * (k / 2).
 Therefore we can calculate the minimum number of swaps in constant time.
Here is the code:


int minSwapNum(string& s, int k) {
    list<int> window;
    int i = 0;
    while ((i < s.size()) && (window.size() < k)) {
        if (s[i] == 'G') {
            window.push_back(i);
        }
        i++;
    }
    //No enough girls
    if (window.size() < k) {
        return -1;
    }
    auto med_it = window.begin();
    advance(med_it, (k - 1) / 2);
    int left_dist = 0;
    int right_dist = 0;
    for (auto idx : window) {
        if (idx < *med_it) {
            left_dist += (*med_it - idx);
        } else {
            right_dist += (idx - *med_it);
        }
    }
    int adjust_dist = (k % 2 == 0) ? k * k / 4 : (k * k - 1) / 4;
    int min = left_dist + right_dist - adjust_dist;
    for (; i<s.size(); i++) {
        if (s[i] == 'G') {
            int head = window.front();
            int tail = i;
            int old_med = *med_it;
            window.pop_front();
            window.push_back(tail);
            med_it++;
            left_dist = left_dist - (old_med - head) + (*med_it - old_med) * ((k - 1) / 2);
            right_dist = right_dist + (tail - *med_it) - (*med_it - old_med) * (k / 2);
            if (left_dist + right_dist - adjust_dist < min) {
                min = left_dist + right_dist - adjust_dist;
            }
        }
    }
    return min;
}
*/


vector<int> get_char_indices(const string & s, char c) {
    int s_len = s.length();
    vector<int> indices;
    indices.reserve(s_len);
    for (int i = 0; i < s_len; ++i) {
        if (s[i] == c) {
            indices.push_back(i);
        }
    }
    indices.shrink_to_fit();
    return indices;
}

int solution2(const string & s) {
    auto reds = get_char_indices(s, 'R');
    int mid = reds.size() / 2;
    int min_swaps = 0, reds_num = reds.size();
    for (int i = 0; i < reds_num; i++) {
        // number of swaps for each R is the distance to mid, minus the number of R's between them
        min_swaps += abs(reds[mid] - reds[i]) - abs(mid - i);
    }
    return (min_swaps > pow(10, 9)) ? -1 : min_swaps;
}


int solution(const string & s) {
    int red_count = 0;
    // count number of Rs in the string
    for (char c : s) {
        if (c == 'R') ++red_count;
    }
    // Init indexes to the ends of the string and the result
    int left = 0, right = s.size() - 1, result = 0;
    // moving from the ends to the middle
    while (left < right) {
        // if we meet pair of Rs on the ends
        if (s[left] == 'R' && s[right] == 'R') {
            // add the the result number of Ws between of these Rs
            red_count -= 2;
            result += right - left - 1 - red_count;
            // and shrink the processing window
            ++left;
            --right;
        }
        // pass all Ws we meet
        else if (s[left] != 'R') {
            ++left;
        }
        else {
            --right;
        }
    }
    return result;
}




int main() {

    cout << solution("RRRWRR") << " Expected: 2" << endl;
    cout << solution("WRRWWR") << " Expected: 2" << endl;
    cout << solution("WWRWWWRWR") << " Expected: 4" << endl;
    cout << solution("RWRWWRRR") << " Expected: 5" << endl;


    return 0;
}

