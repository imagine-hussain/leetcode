#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;

        int lo = newInterval[0];
        int hi = newInterval[1];

        for (auto interval : intervals) {
            if (overlap(interval, newInterval) || overlap(newInterval, interval) ) {
                lo = min(interval[0], newInterval[0]);
                hi = max(interval[1], newInterval[1]);
            }
        }

        for (auto interval : intervals) {
        }

        return vector<vector<int>>();
    }

    // Check v1 inside v2 or overlap
    bool overlap(vector<int> v1, vector<int> v2) {
        return (
            (v1[0] <= v2[1] && v1[1] >= v2[0])
            || (v1[1] <= v2[1] && v1[1] >= v2[0])
        );
    }

};
