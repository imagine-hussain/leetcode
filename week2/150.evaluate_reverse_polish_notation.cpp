#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.size() == 1) {
            return stoi(tokens[0]);
        }

        // Last one
        char operation = tokens[tokens.size() - 1][0];
        int lhs = stoi(tokens[0]);

        vector<string> rhs_tokens (tokens.begin() + 1 , tokens.end() - 1);
        int rhs = evalRPN(rhs_tokens);

        switch (operation) {
            case '+':
                return lhs + rhs;
            case '-':
                return lhs - rhs;
            case '*':
                return lhs * rhs;
            case '/':
                return lhs / rhs;
        }

        return 0;
    }
};
