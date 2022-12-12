#include <algorithm>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> v1 = editor_tranform(s);
        stack<char> v2 = editor_tranform(t);

        return v1 == v2;
    }

    stack<char> editor_tranform(string s) {
        stack<char> stck;
        for (auto c : s) {
            if (c == '#') {
                if (!stck.empty()) stck.pop();
            } else {
                stck.push(c);
            }
        }
        return stck;
    }

};
