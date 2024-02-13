#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return do_dp(dp, s, 0);
    }

    int do_dp(vector<int>& dp, string& s, int i) {
        if (i >= s.size()) return 1;
        if (s[i] == '0') return 0;
        if (dp[i] != -1) return dp[i];

        int one = do_dp(dp, s, i + 1);
        int two = (can_double(s, i)) ? do_dp(dp, s, i + 2) : 0;

        return dp[i] = one + two;
    }

    bool can_double(string& s, int i) {
        return (
            i + 1 < s.size()
            && (s[i] == '1' || (s[i] == '2' && s[i + 1] >= '0' && s[i + 1] <= '6'))
        );
    }

};
