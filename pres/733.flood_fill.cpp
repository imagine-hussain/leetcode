#include <vector>
#include <stdlib.h>
using namespace std;



class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) return image;

        dfs(image, sr, sc, image[sr][sc], color);

        return image;
    }

    void dfs (vector<vector<int>>& grid, int x, int y, int pre_replace, int post_replace) {
        if (grid[x][y] != pre_replace || x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size())
            return;
        grid[x][y] = post_replace;

        for (int x_off = -1; x_off <= 1; x_off++)
            for (int y_off = -1; y_off <= 1; y_off++)
                if (abs(x_off) != abs(y_off))
                    dfs(grid, x + x_off, y_off, pre_replace, post_replace);
    }
};
