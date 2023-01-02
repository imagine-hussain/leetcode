#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> word_set(wordDict.begin(), wordDict.end());
        // Create DP
        vector<vector<bool>> dp = init_dp(s, word_set);

        return dfs(dp);
    }

    vector<vector<bool>> init_dp(string s, unordered_set<string> str_set) {
        int n = s.size();
        vector<vector<bool>> res(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                string substr = s.substr(i, j);
                if (str_set.contains(substr)) {
                    cout << "trueism" << endl ;
                    res[i][j] = true;
                }
            }
        }
        return res;
    }

    bool dfs(vector<vector<bool>>& dp) {
        vector<bool> visited(dp.size(), false);
        visit(dp, visited, 0);

        return visited[dp.size() - 1];
    }

    void visit(vector<vector<bool>>& dp, vector<bool>& visited, int curr) {
        if (visited[curr]) return;
        visited[curr] = true;


        // Visit all neighbours
        for (int i = 0; i < dp.size(); i++) {
            if (dp[curr][i] && !visited[i])
                visit(dp, visited, curr);
        }

    }


};
