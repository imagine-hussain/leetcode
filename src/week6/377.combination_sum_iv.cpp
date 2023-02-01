#include <vector>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        
        vector<int> dp(target + 1, 0);
        for (auto num : nums) {
            dp[num]++;
        }

        for (int i = 0; i <= target; i++) {
            int subtotal = 0;
            for (auto num : nums) {
                if (i - num >= 0)
                    subtotal += dp[i - num];
            }
        }

        return dp[target];
    }
};
