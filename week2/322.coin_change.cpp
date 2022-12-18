#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // -1 := no soln, -2 := not visited yet
        vector<int> dp(amount + 1, -2);

        dp[0] = 0;
        return dpCoinChange(dp, coins, amount);
    }

    int dpCoinChange(vector<int>& dp, vector<int>& coins, int amount) {

        if (amount < 0) return -1;
        if (dp[amount] != -2) return dp[amount];

        int min = INT32_MAX;
        bool atleast_one_solution = false;

        for (auto coin : coins) {
            if (coin == amount) return 1;

            int curr = dpCoinChange(dp, coins, amount - coin);
            if (curr != -1 && curr < min) {
                atleast_one_solution = true;
                min = curr;
            }
        }

        dp[amount] = (atleast_one_solution) ? min + 1: -1;
        return dp[amount];
    }

};
