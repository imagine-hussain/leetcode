#include <vector>
#include <queue>
#include <tuple>
#include <iostream>

using namespace std;

#define ROTTING 2
#define HEALTHY 1


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<tuple<int, int>> q;

        int next_round = 0;
        int day = 0;

        // Initial queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == ROTTING) {
                    next_round += enqueue_neighbours_bfs(grid, q, i, j);
                }
            }
        }

        while (!q.empty()) {
            day += 1;
            int curr_left = next_round;
            next_round = 0;

            while (curr_left > 0) {
                tuple<int, int> pos = q.back();

                get<0>(pos);
                q.pop();

                int i = get<0>(pos);
                int j = get<1>(pos);
                if (grid[i][j] != HEALTHY) {
                    curr_left -= 1;
                    continue;
                }
                grid[i][j] = ROTTING;
                // Make current rotten
                next_round += enqueue_neighbours_bfs(grid, q, get<0>(pos), get<1>(pos));

                std::cout << "round next:  " << next_round << std::endl;

                curr_left -= 1;
            }
        }

        return day;
    }

    int enqueue_neighbours_bfs(vector<vector<int>>& grid, queue<tuple<int, int>>& q, int i, int j) {
        int q_count = 0;


        return  (
              try_enqueue(grid, q, i - 1, j)
            + try_enqueue(grid, q, i + 1, j)
            + try_enqueue(grid, q, i, j - 1)
            + try_enqueue(grid, q, i, j + 1)
        );
    }

    bool try_enqueue(vector<vector<int>>& grid, queue<tuple<int, int>>& q, int i, int j) {
        if (i < 0 || j < 0 || i > grid.size() - 1 || j > grid[0].size() - 1) {
            return false;
        }

        if (grid[i][j] != HEALTHY) {
            return false;
        }

        q.push(tuple<int, int>(i, j));
        return true;
    }

};
