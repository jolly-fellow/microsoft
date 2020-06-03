#include <iostream>
#include <vector>

using namespace std;

/*
Idea:

Scan the string from left to right
1. drop all sequences of the same chars longer than 2;
2. count length of sequences of different chars;
3. save length of the longest sequence.

Algorithm:

We should have a counter of the same chars and index which points to the last two chars of this sequence.
Lets call them "count" and "start"

And we should have two variable where we will save length of the longest sequence of different chars
and index which points to the beginning of this sequence.
Lets call them "max_length" and "start_ml"

So the algorithm in general:

Scan the string from left to right:

0. Take next char of the string;
1.1 If next char is the same as the previous one increase counter of the same chars "count";
1.2 If next char is different drop counter of the same chars "count" to 1;

2 If number of previous the same chars is:
2.1 More than 2. Move pointer to the beginning of the current sequence of different chars "start" to
the previous char before the current one, to keep only two the same chars at the beginning of the sequence.
drop counter of the same chars "count" to 2.
2.2. Less or equal 2. Check if current sequence of different chars is longer than current maximum.
If yes - update maximum to the current length. Save pointer to the beginning of the new longest sequence.
3. Go to phase 0;
*/

string solution(const string &s) {
    int s_size = s.size();
    // start position and length of the longest sequence
    // which doesn't contain 3 contiguous occurrences of a and b
    int start_ml = 0, max_length = 0;

    int start = 0; // start of current processing string of the same letters.
    int count = 1; // length of current processing string of the same letters.

    for (int i = 1; i < s_size; ++i) {

        if (s[i] == s[i - 1]) {
            // if we met two the same letters increase the counter of the same letters
            count++;
        }
        else {
            // if next letter is different drop the counter to 1
            count = 1;
        }
        if (count <= 2) {
            // if the sequence of different letters continuing, set it's current length as
            // max_length if it is bigger than current max_length
            // "i - start + 1" is length of the current processed sequence
            if (i - start + 1 > max_length) {
                max_length = i - start + 1;
                start_ml = start;
            }
        }
        else {
            // if the sequence of the same letters continuing,
            // move the pointer to points to the last two chars of this sequence
            // drop the count to 2
            start = i - 1;
            count = 2;
        }
    }
    return s.substr(start_ml, max_length);
}

int main() {

    cout << "Result: " << solution("aabbaabbaabbaa") << " Expected: aabbaabbaabbaa" << endl;
    cout << "Result: " << solution("aabbaaaaabb") << " Expected: aabbaa" << endl;

    return 0;
}

