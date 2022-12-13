#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";

        string *first = &strs[0];
        int max_common_len = first->length();

        for (auto str : strs)
            max_common_len = min(max_common_len, common_len(*first, str));

        return strs[0].substr(0, max_common_len);
    }

    int common_len(string a, string b) {
        int min_len = min(a.length(), b.length());

        for (int i = 0; i < min_len; i++) {
            if (a[i] != b[i])
                return i;
        }

        return min_len;
    }

};
