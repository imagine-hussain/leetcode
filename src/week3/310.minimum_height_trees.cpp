#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> sorted = top_sort(n, edges);

        return vector<int>();
    }

    vector<int> top_sort(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        queue<int> q;

        // incoming_count
        vector<int> incoming_count(n, 0);
        vector<vector<int>> outgoing(n);
        init_outgoing_incoming(edges, outgoing, incoming_count);

        init_least(q, incoming_count);

        // do topsort
        vector<int> ts;
        ts.reserve(n);

        while (!q.empty()) {
            int curr = q.back();
            q.pop();
            if (visited[curr]) continue;
            visited[curr] = true;
            ts.push_back(curr);

            for (auto u : outgoing[curr]) {
                if (!visited[u])
                    q.push(u);
            }

        }

        vector<int> res;
        if (n == 0) {
            return res;
        }
        // res.push_back(ts.pop_back());
        res.push_back(ts.back());
        ts.pop_back();
        if (n % 2 == 1) {
            return res;
        }
        res.push_back(ts.back());
        return res;
    }

    void init_least(queue<int>& q, vector<int>& incoming) {
        for (int i = 0; i < incoming.size(); i++) {
            if (incoming[i] == 0)
                q.push(i);
        }
    }

    void init_outgoing_incoming(
        vector<vector<int>>& edges,
        vector<vector<int>> &outgoing,
        vector<int>& incoming
    ) {
        for (auto edge : edges) {
            outgoing[edge[1]].push_back(edge[0]);
            incoming[edge[1]]++;
        }
    }

};
