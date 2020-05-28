#include <iostream>
#include <string>

using namespace std;
/*
 To solve this task we need to find sequences of the same letters and if the sequence is longer than 3
 divide length of this sequence to 3 and add result of the division to counters of needed swaps

 Example of work:
3 consecutive : baaab, replace the middle a (3 / 3 == 1)
4 consecutive : baaaab, replace the third a (4 / 3 == 1)
5 consecutive : baaaaab, replace the third a (5 / 3 == 1)
6 consecutive : baaaaaab -> baabaaab -> baaab -> bab with 2 replancement (6 / 3 == 2)
10 consecutive : baaaaaaaaaab -> baabaaaaaaab -> baaaaaaab -> baaaab -> baab with 3 replacement (10 / 3 == 3)

therefore, we can see the rule, counter += (consecutive char number) / 3
 */

int solution(const string & s){
    int res = 0, s_size = s.size();
    for(int i = 0; i < s_size;) {
        int next = i + 1;
        // if we meet sequence of the same letters
        // scanning the string to find length of this sequence
        while( (next < s_size) && (s[i] == s[next]) ) { next++; }
        // Here "next - i" is length of the sequence
        // Each third letter should be changed to remove too long sequences
        res += (next - i) / 3;
        i = next; // skip processed letters
    }
    return res;
}

int main() {

    cout << "Result " << solution("baaaaa") << " expected: 1" << endl;
    cout << "Result " << solution("baaabbaabbba") << " expected: 2" << endl;
    cout << "Result " << solution("baabab") << " expected: 0" << endl;

    return 0;
}

