#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;
        backtrack(0, nums, results);
        return results;
    }

private:

    void backtrack(int first, vector<int> &nums, vector<vector<int>> &results) {
        if (first >= nums.size()) {
            results.push_back(vector<int>(nums));
            return;
        }

        for (int i = first; i < nums.size(); i++) {
            swap(nums[first], nums[i]);
            backtrack(first + 1, nums, results);
            swap(nums[first], nums[i]);
        }
    }

};

