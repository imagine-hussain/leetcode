#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();

        bool clear_first_col = false;
        bool clear_first_row = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    if (i == 0)
                        clear_first_row = true;
                    if (j == 0)
                        clear_first_col = true;
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < n; i++)
            if (matrix[i][0] == 0)
                for (int j = 0; j < m; j++)
                    matrix[i][j] = 0;

        for (int j = 1; j < m; j++)
            if (matrix[0][j] == 0)
                for (int i = 0; i < n; i++)
                    matrix[i][j] = 0;

        if (clear_first_col)
            for (int i = 0; i < n; i++)
                matrix[i][0] = 0;

        if (clear_first_row)
            for (int j = 0; j < m; j++)
                matrix[0][j] = 0;
    }
};
