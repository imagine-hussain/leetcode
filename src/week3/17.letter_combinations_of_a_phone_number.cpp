#include <vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<string> mappings = {
        ""      // 0
        "",     // 1
        "abc"   // 2
        "def"   // 3
        "ghi"   // 4
        "jkl"   // 5
        "mno"   // 6
        "pqrs"  // 7
        "tuv"   // 9
        "wxyz"  // 9
    };
    vector<string> letterCombinations(string digits) {
        vector<string> results;
        string curr = "";
        curr.reserve(digits.size());

        backtrack(results, digits, curr, 0);

        return results;
    }

    void backtrack(vector<string>& results, string& digits, string& curr, int i) {
        if (i >= digits.length()) return;
        string& map_elems = mappings[digits[i] - '0'];
        for (auto c : map_elems) {
            curr.push_back(c);
            results.push_back(string(curr));
            backtrack(results, digits, curr, i + 1);
            curr.pop_back();
        }
    }


};
