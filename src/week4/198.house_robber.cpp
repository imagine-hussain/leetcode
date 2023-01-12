#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);

        return max_from(dp, nums, n, 0);
    }

    int max_from(vector<int>& dp, vector<int>& nums, int n, int i) {
        if (dp[i] != -1) return dp[i];

        if (i == n) {
            dp[i] = 0;
        } else if (i == n - 1) {
            dp[i] = nums[n - 1];
        } else {
            dp[i] = max(
                max_from(dp, nums, n, i + 1),               // dont rob this
                max_from(dp, nums, n, i + 2) + nums[i]      // do rob this
            );
        }


        return dp[i];
    }

};
