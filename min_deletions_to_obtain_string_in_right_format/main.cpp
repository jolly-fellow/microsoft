#include <iostream>
#include <vector>

using namespace std;
/*
DP approach: Assume the minimum deletions to format s[0..i] (index 0 to index i in string s) is computed, then the minimum deletions to format s[0..i+1] is:

if(s[i+1] == 'A')
{
// there are two options, either to include this A or exclude,
// if included then all B's before it should be deleted by definition of the task where A must be always before B
// if excluded then the count is minDel[0..i]+1 that is add the A which we going to exclude/delete to the number of deleted items
minDel[0..i+1] = Math.min(countB, minDel[0..i]+1); //countB is the total count of Bs in s[0..i]
}
else
{
// since B is at the end there is no need to exclude this B
minDel[0..i+1] = minDel[0..i];
}

Java Solution:
*/

int solution2(const string & s) {
    const char CHAR_A = 'A';
    int num_Bs = 0, min_dels = 0;


    for(auto c : s) {
        if (CHAR_A == c) {
            //minimum deletions with this character included
            //is equal to count of all Bs before it
            min_dels = min(num_Bs, min_dels + 1);
        }
        else {
            num_Bs++;
            //there is no need to exclude the last B at the end of the string, the min_dels does not change
        }
    }
    return min_dels;
}


int main() {

    cout << solution2("BAAABAB") << " Expected: 2" << endl;
    cout << solution2("BBABAA") << " Expected: 3" << endl;
    cout << solution2("B") << " Expected: 0" << endl;
    cout << solution2("BAAABBBB") << " Expected: 1" << endl;
    cout << solution2("BBBBABBB") << " Expected: 1" << endl;
    cout << solution2("AAAAA") << " Expected: 0" << endl;

    return 0;
}

