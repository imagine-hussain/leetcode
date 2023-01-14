#include <tuple>
#include <vector>

using namespace std;

typedef tuple<int, int> point;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;

        vector<vector<bool>> to_pacific(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<bool>> to_atlanti(heights.size(), vector<bool>(heights[0].size(), false));

        return res;
    }

};
