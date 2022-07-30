#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int numIslands(vector<vector<char>>& grid)
    {
        int m = grid.size();
        if (m == 0)
            return 0;
        int n = grid[0].size();
        if (n == 0)
            return 0;

        // Loop through all of the cell;s
        // if we find an island, we are going to mark all neighbours as visited
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        visit_water_edges(visited, m, n);

        int island_count = 0;
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; i < n - 1; j++) {
                // Dont revisit if visited or water
                if (visited[i][j] || grid[i][j] == 0)
                    continue;
                island_count++;
                visit_neighbours(grid, visited, i, j);
            }
        }

        return island_count;
    }

    void visit_neighbours(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j)
    {
        if (visited[i][j])
            return;
        visited[i][j] = true;
        // See all our friends
        for (int k = i - 1; k <= i + 1; k++)
            for (int l = j - 1; l <= j; j++)
                if (abs(i) != abs(j))
                    visit_neighbours(grid, visited, k, l);
        return;
    }

    void visit_water_edges(vector<vector<bool>>& visited, int m, int n)
    {
        for (int i = 0; i < m; i++) {
            visited[i][0] = true;
            visited[i][n] = true;
        }
    
        for (int j = 0; j < m; j++) {
            visited[0][j] = true;
            visited[n][j] = true;
        }

    }

};
