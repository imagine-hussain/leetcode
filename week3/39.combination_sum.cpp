#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>

using namespace std;


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> results;
        vector<int> curr(candidates.size());
        backtrack(candidates, results, target, curr);
        return translate(candidates, results);
    }

private:

    vector<vector<int>> translate(vector<int>& candidates, vector<vector<int>>& results) {
        vector<vector<int>> res;
        for (auto v :  results ) {
            vector<int> translated = translate_one(candidates, v);
            res.push_back(translated);
        }
        return res;
    }

    bool elem_in_vec(vector<int>& elem, vector<vector<int>>& vec) {
        for (auto entry : vec) {
            if (entry == elem) return true;
        }
        return false;
    }

    vector<int> translate_one(vector<int>& candidates, vector<int>& v) {
        vector<int> res;
        for (int i = 0; i < v.size(); i++) {
            for (int rpts = 0; rpts < v[i]; rpts++) {
                res.push_back(candidates[i]);
            }
        }
        return res;
    }

    int sum_vec(vector<int>& curr, vector<int>& candidates) {
        int res = 0;
        for (int i = 0; i < curr.size(); i++) {
            res += curr[i] * candidates[i];
        }
        return res;
    }

    void backtrack(vector<int>& candidates, vector<vector<int>>& results, int target, vector<int>& curr) {
        int sum = sum_vec(curr, candidates);
        if (sum == target) {
            if (!elem_in_vec(curr, results)) results.push_back(vector<int>(curr));
            return;
        } else if (sum > target) {
            return;
        }
        for (int i = 0; i < candidates.size(); i++) {
            curr[i]++;
            backtrack(candidates, results, target, curr);
            curr[i]--;
        }
    }

};


