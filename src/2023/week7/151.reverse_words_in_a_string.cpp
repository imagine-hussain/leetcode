#include <iostream>

using std::string;

class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        
        for (int hi = s.size() - 1; hi >= 0; hi--) {
            while (s[hi] == ' ')
                hi--;
            int lo = hi - 1;
            while (lo >= 0 && s[lo] != ' ')
                lo--;
            lo++;
            res += s.substr(lo, hi - lo + 1);
        }

        return res;
    }
};
