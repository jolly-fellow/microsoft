#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * General idea of the algorithm:
 * palindrome has mirrored sides where letters on the same distance from the middle of the word are the same.
 *
 * 0. Check if given string is a shuffled palindrome. If no return -1.
 *
 * 1. We checking if the letters from both sides are the same stared from edges of the word toward the center
 * If the check is OK for all letters we return 0 because it is a correct palindrome and we should move nothing.
 *
 * 2. If we meet different letters we trying to find the same letter going from the end to the beginning of the word
 * 2.1. If we meet the same letter we shift it by swaps to it's right place and return to the phase 1
 * 2.2. If we don't meed the same letter we swap the first letter with it's neighbour and return to the phase 1.
 *
 * 3. Count all swaps and return the number.
 *
 *
     * Algorithm:
     *     1. First check the given string is a jumbled/shuffled palindrome or not.
     *     2. Next have two pointers p1 at 0 and p2 at s.length - 1 and start iterating.
     *     3. If chars at both the pointers are same then just shrink the window (increase the p1 and decrease the p2).
     *     4. or Else
     *          a. find the matching pair and swap the char to p2 index (increase swap count while swapping) and finally shrink the window.
     *          b. if not found just swap once with adjacent index and increase the swap count (do not shrink the window here)
     *     5. Print the Swap Count
     *
     * Time Complexity: O(n) to find Palindrome + [ O(n) for two pointer iteration * O(n) for checking and swapping ] so => O(n^2)
     * Space Complexity: O(n)
     *
     */


bool is_palindrom(const string & word){
    int i1 = 0;
    int i2 = word.size() - 1;
    while (i2 > i1) {
        if (word[i1] != word[i2]) {
            return false;
        }
        ++i1;
        --i2;
    }
    return true;
}

bool is_shuffled_palindrome(const string & s) {
    vector<int> occurrence(26, 0);
    int odd_count = 0;

    for(char i : s) { occurrence[i - 'a']++; }
    for (int value : occurrence) {
        if (value % 2 != 0) {
            odd_count++;
        }
    }
    return odd_count <= 1;
}

/*
int solution(string s) {
    int start = 0;
    int end = s.size() - 1;
    int result = 0;
    while (start < end) {
        // if we found different chars
        if (s[start] != s[end]) {
            int i = end; // make an additional iterator from the end

            // move toward the start until we found the same char
            while (i > start && s[i] != s[start]) { --i; }

            // if we have not scanned whole string yet
            if (i > start) {
                // swap all chars from i to the end
                while (i < end) {
                    swap(s[i], s[i + 1]);
                    result++;
                    i++;
                }
            }
                // if we scanned whole the string and found
                // no one the same char swap char on the start with adjacent char
                // it needs for case when the first char is not on it's right place
                // all other parts of the algorithm don't process a char on the start
                // we don't need to shrink the processing window here so we start
                // a new iteration of the loop here.
            else {
                swap(s[start], s[start+1]);
                result++;
                continue;
            }
        }
        // if s[start] == s[end] shrink the processing window
        start++;
        end--;
    }
    return result;
}
*/

int solution(string s) {
    int s_size = s.size();
    int result = 0;
    int start = 0, end = s_size - 1;

    // if string is empty or it is not a palindrome return -1
    if ((s_size == 0) || (!is_shuffled_palindrome(s))) {
        return -1;
    }

    while (end > start) {
        // if we found different chars
        if (s[start] != s[end]) {
            int i = end; // make an additional iterator from the end

            // move toward the start until we found the same char
            while (i > start && s[i] != s[start]) { --i; }

            // if we scanned whole the string and found
            // no one the same char swap char on the start with adjacent char
            // it needs for case when the first char is not on it's right place
            // all other parts of the algorithm don't process a char on the start
            if (i == start) {
                swap(s[start], s[start + 1]);
                ++result;
            }
            // if the same character found swap all chars from i to the end
            else {
                while (i < end) {
                    swap(s[i], s[i + 1]);
                    ++result;
                    ++i;
                }
                ++start; --end;
            }
        }
        // if s[start] == s[end] shrink the processing window
        else {
            ++start; --end;
        }
    }
    return result;
}

int main() {

//    cout << solution("ntain") << endl;
    cout << solution("abcba") << endl;
    cout << solution("ntaiain") << endl;
    cout << solution("niaiatn") << endl;
    cout << solution("damam") << endl;
    cout << solution("mamad") << endl;

    return 0;
}

