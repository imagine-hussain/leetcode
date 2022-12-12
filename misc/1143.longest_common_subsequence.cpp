#include <algorithm>

// TODO: Doesn't work atm

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // Want to solve opt(i, j)

        // Create a n * m vector to store the opt(i, j). Use `-1` to represent `uninitialized`
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> memos(n + 1, vector<int>(m + 1, -1));
        return opt(text1, text2, n, m, memos);
    }

    int opt(string s1, string s2, int i, int j, vector<vector<int>> &memos) {
        // If already computed, return the value
        if (memos[i][j] != -1) {
            return memos[i][j];
        }
        // Base case
        if (i == 0 || j == 0) {
            memos[i][j] = 0;
            return 0;
        }

        int curr_sol;
        if (s1[i] == s1[j]) {
            curr_sol = opt(s1, s2, i - 1, j - 1, memos) + 1;  
        } else {
            curr_sol = max(
                opt(s1, s2, i - 1, j, memos),
                opt(s1, s2, i, j - 1, memos)
            );
        }
        memos[i][j] = curr_sol;
        return curr_sol;
    }
};
