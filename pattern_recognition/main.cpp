#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <unordered_set>
#include <set>

using namespace std;

vector<string> get_top_keywords(const vector<string> & keywords, vector<string> & reviews, int k ) {
    // This map will contains pairs of the keywords and their frequency of their appearance in the reviews
    unordered_map<string, int> map_keys;
    // Reserve buckets for all possible keywords to prevent rehash in process of work
    // It allows to add all keywords in constant time.
    map_keys.reserve(keywords.size());

    // Fill the map with all keywords. Then we will use them to recognize in the text of the reviews
    for(auto & key : keywords) {
        map_keys.emplace(key, 0);
    }

    using key_counter = pair<string, int>;

    // Write a custom comparator which allows to sort the keywords corresponding to the requirements of the task
    auto comp = [](const key_counter & lhs, const key_counter & rhs) -> bool {
        return lhs.second > rhs.second || (lhs.first < rhs.first && lhs.second == rhs.second);
    };

    // We will keep here properly sorted keywords.
    set<key_counter, decltype(comp)> counter_set (comp);

    // Process the reviews one by one
    for(string review : reviews) {
        // transform each review to lower before processing
        std::transform(review.begin(), review.end(), review.begin(),
                       [](unsigned char c){ return std::tolower(c); });
        // This set needs to keep all keywords from the review which were added to
        // count each keyword only one time per review as the task requires
        unordered_set<string> added;
        // This is the most short and obvious way to break a string with many delimiters to tokens. C++ is weak here.
        for(char *token = strtok((char*)review.c_str(), " .,;"); token != NULL; token = strtok(NULL, " .,;")) {
            // If the token is a given keyword and this token was not counted for this review count it.
            if(map_keys.count(token) && !added.count(token)) {
                map_keys[token]++;
                added.emplace(token);
            }
        }
    }
    // Easy and fast way to sort the keywords corresponding to the requirements of the task
    for(auto& e: map_keys) { counter_set.emplace(e); }

    // Take k sorted keywords and add return them as the result
    vector<string> res;
    for(auto& e: counter_set) {
        if(k == 0) { break; }
        res.push_back(e.first);
        --k;
    }
    return res;
}


int main() {
    int k1 = 2;
    vector<string> keywords1 = { "anacell", "cetracular", "betacellular" };
    vector<string> reviews1 = { "Anacell provides the best services in the city",
                                "betacellular has awesome services",
                                "Best services provided by anacell, everyone should use anacell"};
    int k2 = 2;
    vector<string> keywords2 = { "anacell", "betacellular", "cetracular", "deltacellular", "eurocell" };
    vector<string> reviews2 = { "I love anacell Best services; Best services provided by anacell",
                          "betacellular has great services",
                          "deltacellular provides much better services than betacellular",
                          "cetracular is worse than anacell",
                          "Betacellular is better than deltacellular."};

    std::cout << "test 1: " << std::endl;

    auto res = get_top_keywords(keywords1, reviews1, k1);

    for(auto e: res) {
        cout << e << endl;
    }

    std::cout  << std::endl << "test 2: " << std::endl;

    res = get_top_keywords(keywords2, reviews2, k2);

    for(auto e: res) {
        cout << e << endl;
    }

    return 0;
}
