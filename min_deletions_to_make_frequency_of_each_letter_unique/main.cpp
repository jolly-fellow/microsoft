#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;


int solution(const string & s) {
    // counter of characters to delete
    int count = 0;
    // array of counters of occurrences for all possible characters
    vector<int> occurrences('z' - 'a', 0);
    // count the occurrences
    for (char c: s) { ++occurrences[c - 'a']; }

    priority_queue<int> pq;
    // put non zero occurrences into the queue
    for (int c: occurrences) {
        if (c != 0) { pq.push(c); }
    }

    while (!pq.empty()) {
        // take the biggest frequency of a character
        int most_frequent = pq.top(); pq.pop();

        if (pq.empty()) { return count; }
        // if this frequency is equal to the next one
        // and bigger than 1 decrease it to 1 and put
        // back to the queue
        if (most_frequent == pq.top()) {
            if (most_frequent > 1) {
                pq.push(most_frequent - 1);
            }
            ++count;
        }
        // all frequencies which are bigger than
        // the next one are removed from the queue because they are unique
    }
    return count;
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
    cout << "Result: " << solution("eeeeffffaaaa") << " Expected: 3" << endl;
    cout << "Result: " << solution("aabbffddeaee") << " Expected: 6" << endl;
    cout << "Result: " << solution("llll") << " Expected: 0" << endl;
    cout << "Result: " << solution("example") << " Expected: 4" << endl;

    return 0;
}

