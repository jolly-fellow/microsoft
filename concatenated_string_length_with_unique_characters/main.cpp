#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int solution(const vector<string>& v) {
    // We will keep in this vector bitmaps of used letters
    // for the processed words.
    // Add one empty bitset for comparison with the first
    // processed word. It makes the algorithm a bit shorter
    vector<bitset<26>> char_bits_vector = {bitset<26>()};
    int result = 0;
    // for each string in the vector make a bitset where all
    // bits corresponding to characters in alphabet are set.
    for (auto& str : v) {
        bitset<26> char_bits;
        // set bits corresponding to chars in the string.
        for (char c : str) { char_bits.set(c - 'a'); }
        // How many bits were set.
        int bit_num = char_bits.count();
        // the string contains duplicate characters so don't process it
        if (bit_num < str.size()) continue;

        // Check if current word has common letters with already processed words
        for (int i = char_bits_vector.size() - 1; i >= 0; --i) {
            auto& c_b = char_bits_vector[i];
            // if two bitsets have common 1 bits i.e.
            // if two words have common letters don't process current word
            if ((c_b & char_bits).any()) continue;
            // if current word has unique letters add to the vector a bitset where
            // all bits corresponding to letters of the current word are set to 1.
            char_bits_vector.push_back(c_b | char_bits);
            // add length of the current word to the result
            result = max<int>(result, c_b.count() + bit_num);
        }
    }
    return result;
}

int main() {

    cout << solution({"co","dil","ity"}) << " Expected 5" << endl;

    return 0;
}

