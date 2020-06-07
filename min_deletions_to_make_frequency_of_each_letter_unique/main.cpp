#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

int solution0(const string & s) {
    if(s.size() < 2) { return 0; }
    const int CHARS_NUMBER = 'z'-'a';
    int count = 0, processed = 0;
    vector<int> occurrences(CHARS_NUMBER, 0);
    for(char c: s) {
        if(isalpha(c)) {
            occurrences[c-'a']++;
        }
    }

    std::sort(begin(occurrences), end(occurrences), std::greater<int>());

    for (int i = 0; i < CHARS_NUMBER; ++i) {
        processed += occurrences[i];
        if(occurrences[i] <= 2) {
            count += occurrences[i];
        }
        else {
            if (occurrences[i] <= occurrences[i + 1]) {
                ++count;
                occurrences[i + 1] = occurrences[i] - 1;
            }
        }
    }
    return count;
}

int solution(const string & s) {
    int del = 0;
    vector<int> count('z'-'a', 0);
    for (char c: s) {
        count[c-'a']++;
    }

    priority_queue<int> pq;
    // std::priority_queue<int, std::vector<int>, std::greater<int> > q2;
    for (int c: count) {
        if (c != 0) pq.push(c);
    }
    while (!pq.empty()) {
        int curr = pq.top(); pq.pop();
        if (pq.empty()) return del;
        if (curr == pq.top()) {
            if (curr != 1) {
                pq.push(curr - 1);
            }
            del++;
        }
    }
    return del;
}

int solution2(const string & s){
    unordered_map<int,int> char_cnt, cnt_length;
    int max_length = 0, res = 0;

    /* get counter for each char, and get the max number of same char as well */
    for(char c : s)
        max_length = max(max_length,++char_cnt[c]);

    /* get a hash[key] = value : key->char counter, value->the number of char counter = key */
    for(auto it : char_cnt)
        cnt_length[it.second]++;

    /* start from the max, if current layer is more than 1, move the redundant to lower level */
    while(max_length){
        int shift_to_next =  max(0,cnt_length[max_length]-1);
        res += shift_to_next;
        cnt_length[max_length-1] += shift_to_next;
        max_length--;
    }
    return res;
}

int main() {

/*
 aaa
 ee
 b
 ff
 dd
 */

    cout << "Result: " << solution0("aabbffddeaee") << " Expected: 6" << endl;
/*
    cout << "Result: " << solution("eeeeffff") << " Expected: 1" << endl;
    cout << "Result: " << solution("aabbffddeaee") << " Expected: 6" << endl;
    cout << "Result: " << solution("llll") << " Expected: 0" << endl;
    cout << "Result: " << solution("example") << " Expected: 4" << endl;
*/
    return 0;
}

