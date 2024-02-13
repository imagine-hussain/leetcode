#include <vector>

using namespace std;
#define UNVISITED -1
#define LEAST -2

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g = init_graph(edges, n);
        vector<int> prev(n, UNVISITED);

        for (int i = 0; i < n; i++) {
            if (prev[i] == UNVISITED) {
                prev[i] = LEAST;
                dfs(g, prev, i);
            }
        }

        int components = 0;
        for (auto v : prev)
            if (v == LEAST) components++;

        return components;
    }

    void dfs(vector<vector<int>>& g, vector<int>& prev, int u) {
        for (auto& v : g[u]) {
            if (prev[v] != UNVISITED)
                continue;
            prev[v] = u;
            dfs(g, prev, v);
        }
    }

    vector<vector<int>> init_graph(vector<vector<int>>& edges, int n) {
        vector<vector<int>> g(n);

        for (auto& edge : edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }

        return g;
    }


};
