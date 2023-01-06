#include <vector>

using namespace std;

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT,
};

// matrix[i][j] \in [-100, 100]
#define VISITED 1000

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        Direction direction = Direction::RIGHT;
        int n = matrix.size();
        int m = matrix[0].size();
        int mn = m * n;
        vector<int> res;
        res.reserve(m * n);

        int i = 0;
        int j = 0;
        visit(matrix, i, j, res);
        while (res.size() < mn) {
            if (is_direction_change_needed(matrix, direction, i, j))
                direction = next_direction(direction);
            apply_direction(direction, i, j);
            res.push_back(matrix[i][j]);
            matrix[i][j] = VISITED;
        }

        return res;
    }

    inline void visit(vector<vector<int>>& mat, int i, int j, vector<int>& res) {
        res.push_back(mat[i][j]);
        mat[i][j] = VISITED;
    }

    bool is_direction_change_needed(vector<vector<int>>& matrix, Direction dir, int i, int j) {
        apply_direction(dir, i, j);
        if  (i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size())
            return true;
        return matrix[i][j] == VISITED;
    }

    void apply_direction(Direction dir, int& i, int& j) {
        switch (dir) {
            case UP:
                i--;
                break;
            case DOWN:
                i++;
                break;
            case LEFT:
                j--;
                break;
            case RIGHT:
                j++;
                break;
        }
    }

    Direction next_direction(Direction direction) {
        switch (direction) {
            case RIGHT:
                return DOWN;
            case DOWN:
                return LEFT;
            case LEFT:
                return UP;
            case UP:
                return RIGHT;
        }
    }
};
