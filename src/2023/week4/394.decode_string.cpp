#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string decodeString(string s) {

        return do_decode(s, 0, s.length());
    }

    string do_decode(string& s, int lo, int hi) {

        string res;

        int i = lo;
        int multiplier = 1;

        while (i < hi) {

            char c = s[i];

            // not a number or anything
            if (c >= 'a' && c <= 'z') {
                res += s[i];
            }

            // open brack
            if (c == '[') {
                // find closer for this
                int open = 1;
                int k = i;
                while (++k && open) {
                    if (s[i] == '[') open++;
                    if (s[i] == ']') open--;
                }
                string sub_res = do_decode(s, i + 1 , k - 1);
                i = k - 1; // skipp curr tok past the decoded

                res += mult_str(sub_res, multiplier);

                multiplier = 1;
            }

            if (c >= '1' && c <= '9') {
                int k = i;
                while (s[k + 1] <= '9' && s[k + 1] >= '1')
                    k++;
                string sub = s.substr(i, k - i);
                multiplier = stoi(sub);
                i = k;
            }

            i++;
        }

        return res;
    }

    string mult_str(string& s, int multiplier) {
        if (multiplier == 0)
            return "";
        if (multiplier == 1)
            return s;

        string res = string(s);
        res.reserve(s.length() * multiplier);

        while (--multiplier)
            res += s;

        return res;
    }

};
