#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int longest = 0;
        for (int i = 0; i < s.size(); i++) {
            // start at i, keep going *until* we have smth invalid
            int open = 0;
            for (int j = i; j < s.size(); j++) {
                if (s[j] == '(') {
                    open++;
                } else {
                    if (open == 0) break; // invalid
                    open--;
                    if (open == 0) { // become valid
                        int len = (j - i + 1);
                        if (len > longest)
                            longest = len;
                    }
                }
            }
        }
        return longest;
    }

};
