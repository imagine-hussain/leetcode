#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // vector[i][j]
        // := all the ways to make valid parens with `i` open and `j` closed
        // remaining
        vector<vector<vector<string>>> dp(n / 2 + 2, vector<vector<string>>(n / 2 + 2));

        // bases: dp[0][0] = []
        // dp[0][j] := [only_close]; where only_close := ")" * j
        // dp[i][0] := [invalid] -> can't go down this path
        // if i == j -> can only choose the path of adding an open


        do_dp(dp, n / 2, n / 2);

        return dp[n / 2][n / 2];
    }


    void do_dp(vector<vector<vector<string>>>& dp, int i, int j) {
        if (i < 0 || j < 0) return;

        if (i > j) return;


    }

};
