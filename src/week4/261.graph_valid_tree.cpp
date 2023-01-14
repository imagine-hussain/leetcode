#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        vector<vector<int>> graph = init_graph(edges, n);
        stack<int> s;
        s.push(0);

        vector<int> from(n);
        from[0] = 0;

        while (!s.empty()) {
            int top = s.top();
            s.pop();
            if (visited[top])
                return false;
            visited[top] = true;
            for (auto neigbour : graph[top]) {
                if (neigbour == from[top])
                    continue;
                s.push(neigbour);
                from[neigbour] = top;
            }
        }

        for (auto visit : visited)
            if (!visit) return false;
        return true;
    }

private:


    /// adj list; g[u][v] <==> edge(u, v)
    vector<vector<int>> init_graph(vector<vector<int>>& edges, int n) {
        vector<vector<int>> g(n);

        for (auto e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        return g;
    }

};
