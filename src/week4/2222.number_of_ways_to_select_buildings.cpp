#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long numberOfWays(string s) {
        vector<long long> dp(s.size(), -1);
        
        // dp[i] number of ways to select out of s[i...]
        for (int i = s.size() - 1; i >= 0; i--) {
        }

        return 0;
    }
};
