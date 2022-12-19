#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int rows = mat.size();
        if (rows == 0) return mat;

        int cols = mat[0].size();

        // upper bound for row, col is 10-000 -> max dist is 20_000
        vector<vector<int>> dp(rows, vector<int>(cols, 20000));

        // From top--left -> bottom right
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] == 0) {
                    dp[i][j] = 0;
                } else {
                    if (i > 0)
                        dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                    if (j > 0)
                        dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                }
            }
        }

        // From bottom-right -> top-left
        for (int i = rows - 1; i >= 0; i--) {
            for (int j = cols - 1; j >= 0; j--) {
                if (i < rows - 1)
                    dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
                if (j < cols - 1)
                    dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
            }
        }

        return dp;
    }
};
