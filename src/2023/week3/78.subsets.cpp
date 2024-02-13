#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        res.push_back(vector<int>());
        curr.reserve(nums.size());
        res.reserve(1 << nums.size());
        backtrack(res, curr, nums, 0);

        return res;
    }

    void backtrack(vector<vector<int>>& res, vector<int>& curr, vector<int>& nums, int i) {
        // base case
        if (i >= nums.size()) return; // star

        // Option 1: dont include in subset
        backtrack(res, curr, nums, i + 1);

        // Option 2: include in subset
        curr.push_back(nums[i]);
        add_result(res, curr);
        backtrack(res, curr, nums, i + 1);
        // undo choice
        curr.pop_back();
 }

    inline void add_result(vector<vector<int>>& res, vector<int>& curr) {
        res.push_back(vector<int>(curr));
    }
};


