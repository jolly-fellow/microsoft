#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> z_function (const string & s) {
    int n = (int) s.size();
    vector<int> z (n);
    for (int i=1, l=0, r=0; i<n; ++i) {
        if (i <= r)
            z[i] = min (r-i+1, z[i-l]);
        while (i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if (i+z[i]-1 > r)
            l = i,  r = i+z[i]-1;
    }
    return z;
}

int z_count(const std::string & s, const std::string& sub) {
    size_t sub_size = sub.size();
    if ( (sub_size == 0) || (sub_size > s.size()) ) return 0;

    string working_string(sub + s);
    size_t ws_size = working_string.size();

    auto z = z_function(working_string);

    int number_subs = 0;

    for(int i = sub_size; i < ws_size; ++i) {
        if (z[i] >= sub_size) {
//            cout << i - sub_size << endl; //to get position of substrings in the string
            ++number_subs;
        }
    }
    return number_subs;
}


int KMP_count(const string &s, const string &sub) {
    int num_subs = 0;
    size_t sub_size = sub.size();
    size_t s_size = s.size();
    if ((sub_size == 0) || (sub_size > s.size())) { return 0; }
    vector<int> prefixes(sub_size);
    for (int k = 0, i = 1; i < sub_size; ++i) {
        while ((k > 0) && (sub[i] != sub[k])) {
            k = prefixes[k - 1];
        }
        if (sub[i] == sub[k]) { k++; }
        prefixes[i] = k;
    }

    for (int k = 0, i = 0; i < s_size; ++i) {
        while ((k > 0) && (sub[k] != s[i])) {
            k = prefixes[k - 1];
        }
        if (sub[k] == s[i]) { k++; }

        if (k == sub_size) {
            // (i - sub_size + 1); //to get position of substrings in the string
            ++num_subs;
        }
    }
    return num_subs;
}


// if overlapped is false then counts non overlapped substrings
int count_substrings(const std::string & s, const std::string& sub, bool overlapped = true) {
    size_t sub_size = sub.size();
    if ( (sub_size == 0) || (sub_size > s.size()) ) return 0;
    int count = 0;
    for (size_t offset = s.find(sub); offset != string::npos;
         offset = s.find(sub, overlapped ? offset + 1 : offset + sub.size()))

    {
        ++count;
    }
    return count;
}

string parser(const string & s) {
    string output;
    int total_patterns = 0;

    size_t pos = s.find_first_of(';');
    string pattern = s.substr(0, pos);
    string blobs = s.substr(pos+1);

    for(char *token = strtok((char*)blobs.c_str(), "|"); token != NULL; token = strtok(NULL, "|")) {
        string stoken(token);
//        int num_patterns = count_substrings(stoken, pattern);
//        int num_patterns = z_count(stoken, pattern);
        int num_patterns = KMP_count(stoken, pattern);
        total_patterns += num_patterns;
        output.append(to_string(num_patterns));
        output.append("|");
    }
    output.append(to_string(total_patterns));
    return output;
}


int main() {

    /*
Test 1
Test Input
bc;bcdefbcbebc|abcdebcfgsdf|cbdbesfbcy|1bcdef23423bc32
Expected Output
3|2|1|2|8

Test 2
Test Input
aa;aaaakjlhaa|aaadsaaa|easaaad|sa
Expected Output
4|4|2|0|10

Test 3
Test Input
b;bcdefbcbebc|abcdebcfgsdf|cbdbesfbcy|1bcdef23423bc32
Expected Output
4|2|3|2|11

Test 4
Test Input
;bcdefbcbebc|abcdebcfgsdf|cbdbesfbcy|1bcdef23423bc32
Expected Output
0|0|0|0|0

     */

    cout << parser("bc;bcdefbcbebc|abcdebcfgsdf|cbdbesfbcy|1bcdef23423bc32") << " Expected: 3|2|1|2|8" << std::endl;
    cout << parser("aa;aaaakjlhaa|aaadsaaa|easaaad|sa") << " Expected: 4|4|2|0|10" << std::endl;
    cout << parser("b;bcdefbcbebc|abcdebcfgsdf|cbdbesfbcy|1bcdef23423bc32") << " Expected: 4|2|3|2|11" << std::endl;
    cout << parser(";bcdefbcbebc|abcdebcfgsdf|cbdbesfbcy|1bcdef23423bc32") << " Expected: 0|0|0|0|0" << std::endl;


    return 0;
}
