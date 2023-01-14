#include <vector>
#include <tuple>
#include <queue>
#include <optional>
#include <iostream>

using std::get;
using std::queue;
using std::tuple;
using std::vector;

#define START '*'
#define FOOD '#'
#define FREE 'O'
#define OBSTACLE 'X'


class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<tuple<int, int>> q;

        vector<vector<int>> visited(n, vector<int>(m, 0));
        tuple<int, int> start = find_start(grid, n, m);
        q.push(start);

        while (!q.empty()) {
            tuple<int, int> top = q.front();
            q.pop();
            if (visit(grid, visited, q, top))
                return visited[std::get<0>(top)][std::get<1>(top)] + 1;
        }

        return -1;
    }

private:

    bool in_bounds(tuple<int, int>& pos, int rows, int cols) {
        int row = get<0>(pos);
        int col = get<1>(pos);
        return row >= 0 && col >= 0 && row < rows && col < cols;
    }

    bool visit(vector<vector<char>>& grid, vector<vector<int>>& visited, queue<tuple<int, int>>& q, tuple<int, int>& position) {
        int steps = visited[std::get<0>(position)][std::get<1>(position)] + 1;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (abs(i - j) != 1)
                    continue;
                tuple<int, int> pos =
                    tuple<int, int>(get<0>(position) + i, get<1>(position) + j);

                if (!in_bounds(pos, grid.size(), grid[0].size()))
                    continue;

                char c = grid[std::get<0>(pos)][std::get<1>(pos)];

                if (visited[get<0>(pos)][get<1>(pos)])
                    continue;
                if (c == FOOD)
                    return true;
                if (c == OBSTACLE || c == START)
                    continue;

                // empty space; add it to q and visited
                // Check if visited. If not, push
                q.push(pos);
                visited[get<0>(pos)][get<1>(pos)] = steps;
            }
        }

        return false;
    }

    tuple<int, int> find_start(vector<vector<char>>& grid, int rows, int cols) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == START)
                    return tuple<int, int>(i, j);
            }
        }
        // unreachable; can just exit
        return tuple<int, int>(-1, -1);
    }
};
