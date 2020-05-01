#include <iostream>
#include <vector>

using namespace std;

string solution(const string & s){
    int n = s.size();
    int p = 0, q = 0, mx = 0, cnt = 1, st = 0;
    for(int i=1;i<n;i++){
        if(s[i]==s[i-1]){
            cnt++;
        }
        else{
            cnt = 1;
        }
        if(cnt<=2){
            if(i-st+1>mx){
                mx = i-st+1;
                p = st;
            }
        }
        else{
            st = i-1;
            cnt = 2;
        }
    }
    return s.substr(p,mx);
}

int main() {

    cout << "Result: " << solution("aabbaabbaabbaa") << " Expected: aabbaabbaabbaa" << endl;
    cout << "Result: " << solution("aabbaaaaabb") << " Expected: aabbaa" << endl;

    return 0;
}

