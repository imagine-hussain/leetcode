#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> res;
        res.reserve(nums.size());
        for (auto n : nums)
            res.push_back(to_string(n));
        sort(res.begin(), res.end());
        reverse(res.begin(), res.end());

        string r;
        for (auto& s : res)
            r += s;

        return r;
    }
};
