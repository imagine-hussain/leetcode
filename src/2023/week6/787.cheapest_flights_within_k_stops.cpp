#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // dijskta but with bfs
        // stop after k rounds
        vector<int> visited(n, -1);
        vector<vector<int>> g = init_graph(n, flights);
        queue<int> q;
        q.push(src);
        int this_round = 1;
        int next_round = 1;

        for (int round = 0; round < k; round++) {
            this_round = next_round;
            next_round = 0;
            while (this_round--) {
                int curr = q.front();
                q.pop();

                // visit all curr's friends
                for (auto dest : g[curr]) {
                    // not reachable
                    if (dest == -1) continue;

                    // push dest
                    q.push(dest);
                    next_round++;
                }

            }
        }

        return visited[dst];
    }

    vector<vector<int>> init_graph(int n, vector<vector<int>>& edgelist) {
        vector<vector<int>> g(n, vector<int>(n, -1));

        for (auto& edge : edgelist) {
            // edge: [src, dest, weight]
            g[edge[0]][edge[1]] = edge[1];
        }

        return g;
    }

};
