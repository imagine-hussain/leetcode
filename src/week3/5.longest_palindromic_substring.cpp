#include <iostream>
#include <vector>
#include <optional>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int l = 0;
        int r = 0;
        int best_len = 0;

        for (int center = 0; center < n; center++) {
            int len = optimal_at_center(s, center);
            if (len > best_len) {
                best_len = len;
                r = center + (len / 2);
                l = max(center, (center - (len / 2)));
            }
        }

        cout << "best_len:  " << best_len << endl;

        return s.substr(l, r);
    }

    int optimal_at_center(string s, int center) {
        // Assume center to be on lhs if even. center if odd
        if (center == s.size()) return 1;
        if (center == 0) return (s[0] == s[1]) ? 2 : 1;

        int left = center;
        int right = center;
        int best_len = 1;

        for (int len = 2; len < s.size(); len++) {
            // at an even len -> expand to right
            // at odd, expand to left
            if (len % 2 == 0) {
                right += 1;
            } else {
                left += 1;
            }

            if (left < 0 || right >= s.size()) {
                return best_len;
            }

            // assume that inner has been palindrome checked
            bool valid = s[left] == s[right];
            if (valid) {
                best_len = len;
            } else {
                if (best_len < len - 1) return best_len;
            }

        }

        return best_len;
    }

};
