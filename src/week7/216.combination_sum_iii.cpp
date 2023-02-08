#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> curr;

        backtrack(res, curr, k, n, 1);

        return res;
    }

    void backtrack(vector<vector<int>>& res, vector<int>& curr, int k, int n, int up_to) {
        if (n <= 0 || k <= 0) {
            if (n == 0 && k == 0) res.push_back(vector<int>(curr));
            return;
        };

        for (int i = up_to; i <= 9; i++) {
            // add + recurse
            // Option 1: Try it by adding the next number
            curr.push_back(i);
            backtrack(res, curr, k - 1, n - i, i);
            curr.pop_back();
            // Option 2: Try it without this number
            backtrack(res, curr, k, n, i);
        }

    }

};
