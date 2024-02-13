#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1)
            return intervals;

        sort(intervals.begin(), intervals.end(), // Sort by start time
            [](const auto& lhs, const auto& rhs ) { return lhs[0] < rhs[0]; });

        vector<int> prev = intervals[0];
        vector<vector<int>> res;
        for (int i = 1; i < intervals.size(); i++) {
            if (is_overlap(prev, intervals[i])) {
                prev[1] = max(intervals[i][1], prev[1]); // Merge
            } else {
                res.push_back(prev);
                prev = intervals[i];
            }
        }
        res.push_back(prev);

        return res;
    }

private:
    // Assume lhs starts <= rhs
    bool is_overlap(vector<int>& lhs, vector<int>& rhs) {
        // [    (  ] )
        return lhs[0] <= rhs[0] && rhs[0] <= lhs[1];
    }

};
