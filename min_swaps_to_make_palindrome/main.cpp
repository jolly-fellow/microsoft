#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/*
int solution(string s) {
        int start = 0;
        int end = s.size() - 1;
        int ret = 0;
        while (start < end)
        {
            if (s[start] != s[end])
            {
                int idx = end;
                for (; idx > start; --idx)
                {
                    if (s[idx] == s[start])
                    {
                        break;
                    }
                }

                if (idx > start)
                {
                    while (idx < end)
                    {
                        swap(s[idx], s[idx+1]);
                        ret++;
                        idx++;
                    }
                }
                else
                {
                    ret = -1;
                    break;
                }
            }
            start++;
            end--;
        }
        return ret;
}
*/

bool is_palindrom(const string & word){
    int i1 = 0;
    int i2 = word.length() - 1;
    while (i2 > i1) {
        if (word[i1] != word[i2]) {
            return false;
        }
        ++i1;
        --i2;
    }
    return true;
}

bool is_shuffled_palindrome(string s) {
    vector<int> occurrence(26, 0);
    int oddCount = 0;

    for(char i : s) occurrence[i - 'a']++;
    for (int value : occurrence) if (value % 2 != 0) oddCount++;
    return oddCount <= 1;
}

int solution(const string & inputStr)
{
    if(!is_shuffled_palindrome(inputStr)) { return -1; }

    int n = inputStr.length();
    int result = 0;
    string items = inputStr;
    for(int i = 0; i< n/2; i++)
    {
        bool found = false;
        for(int j = n-i-1; j >= i+1; j--)
        {
            if (items[i] != items[j])
                continue;
            found = true;
            for(int k = j; k < n - i - 1; k++)
            {
                char temp = items[k];
                items[k] = items[k+1];
                items[k+1] = temp;
                result++;
            }
            break;
        }
        if(!found && n%2 == 1)
        {
            for(int k = i; k < n/2; k++)
            {
                char temp = items[k];
                items[k] = items[k + 1];
                items[k + 1] = temp;
                result++;
            }
        }
    }
    return result == 0 ? -1 : result;
}

int main() {

    cout << solution("ntain") << endl;

    return 0;
}

