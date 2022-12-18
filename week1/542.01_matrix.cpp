#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        stack<int> x;

        vector<vector<int>> dp;

        int m = mat.size();
        int n = mat[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int pred_i = (i - 1 < 0) ? 0 : mat[j][i - 1];
                int pred_j = (j - 1 < 0) ? 0 : mat[j - 1][i];
            }
        }


        return mat;
    }
};
