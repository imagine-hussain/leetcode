#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;

        unordered_map<string, vector<string>> anagram_map;
        for (string str : strs) {
            string sorted = str;
            sort(str.begin(),  str.end());
            if (anagram_map.count(sorted) == 0) {
                anagram_map.emplace(sorted, vector<string>());
            }
            anagram_map.at(sorted).push_back(str);
        }

        res.reserve(anagram_map.size());
        for (auto entry : anagram_map) {
            res.push_back(entry.second);
        }


        return res;
    }
};
