#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int lo = 0;
        int hi = height.size() - 1;

        while (lo < hi) {
            int curr_area = (hi - lo) * (min(height[hi], height[lo]));
            max_area = max(max_area, curr_area);

            // update pointer - move the smaller one
            if (height[lo] < height[hi]) {
                lo++;
            } else {
                hi--;
            }

        }


        return max_area;
    }
};
