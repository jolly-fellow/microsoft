#include <iostream>
#include <vector>

using namespace std;

string solution(string s) {

     int i=0;
     for(; i<s.length()-1; i++){
         if(s[i] > s[i+1]){
             break;
         }
     }

    s.erase(i,1);

     return s;
 }

int main() {

    cout << "Result: " << solution("abczd") << " Expected: abcd" << endl;

    return 0;
}

