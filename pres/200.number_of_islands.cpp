#include <vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands += 1;
                    remove_islands(grid, i, j, m, n);
                }
            }
        }
        return islands;
    }
    void remove_islands(vector<vector<char>>& grid, int i, int j, int m, int n) {
        // Check bounds and not water
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0')
            return;

        grid[i][j] = '0';
        remove_islands(grid, i, j - 1, m, n);   // left
        remove_islands(grid, i, j + 1, m, n);   // right
        remove_islands(grid, i - 1, j, m, n);   // up
        remove_islands(grid, i + 1, j, m, n);   // down
    }
};
