#include <iostream>
#include <map>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string, tuple<int, int>> m;
        // 0 incoming
        // 1 outgoing
        for (auto& path : paths) {
            string& src = path[0];
            string& dst = path[1];
            if (m.find(src) == m.end())
                m.emplace(src, tuple<int, int>(0, 0));
            if (m.find(dst) == m.end())
                m.emplace(dst, tuple<int, int>(0, 0));
            auto& lhs = m.find(src)->second;
            auto& rhs = m.find(dst)->second;
        }

        for (auto& path : m) {
            if (get<0>(path.second) && !get<1>(path.second))
                return path.first;
        }

        return "";
    }
};
