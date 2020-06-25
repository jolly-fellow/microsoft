#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

int solution(const string & s) {
    int s_size = s.size();
    // the solution make sense only for strings longer than 2 chars.
    if(s_size < 2) { return 0; }
    // get number of letters in given alphabet
    const int CHARS_NUMBER = 'z'-'a';
    int count = 0, processed = 0;
    // we will keep here number of occurrences of the letters
    vector<int> occurrences(CHARS_NUMBER, 0);

    // count number of occurrences of the letters in given string
    for(char c: s) { occurrences[c-'a']++; }

    // sort the array of the occurrences
    // on this stage we don't need to know which letter exactly has which number of occurrences
    // because we need to find only number of letters to remove
    // so the sorting and losing alphabet order of letters is not important
    std::sort(begin(occurrences), end(occurrences), std::greater<int>());

    // here we processing all numbers of occurrences
    // since we need only count how many letters we need to remove
    // we don't need to actually change numbers of occurrences themselves
    // we just have to count letters to delete like we changed the occurrences
    for (int i = 0; i < CHARS_NUMBER - 1; ++i) {
        processed += occurrences[i];

        switch (occurrences[i]) {
            case 0:
                // if we processed all letters just return the counter
                return count;
            case 2:
                // of we met line with 2 occurrences we remove one letter to make a stair step
                // from one letter so increase the counter
                if(i == 0) { ++count; }
            case 1:
                // in case we met 1 or 2 occurrences we don't have to precess
                // all other occurrences because we may calculate number of characters left to process
                // if we subtract from length of given string number of processed chars + number of chars to remove
                return s_size - (processed + count);
            default: {
                // if number of occurrences is greater than 2 check if the same as the next one
                // if yes remove one letter to make a stair step and jump to the next step.
                if (occurrences[i] <= occurrences[i + 1]) {
                    ++count; ++i;
                }
            }
        }
    }
    return count;
}


int solution0(const string & s) {
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

    cout << "Result: " << solution("eeeeffff") << " Expected: 1" << endl;
    cout << "Result: " << solution("aabbffddeaee") << " Expected: 6" << endl;
    cout << "Result: " << solution("llll") << " Expected: 0" << endl;
    cout << "Result: " << solution("example") << " Expected: 4" << endl;

    return 0;
}

