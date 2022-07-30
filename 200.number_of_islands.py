from typing import List
    
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        islands = 0
        for i, row in enumerate(grid):
            for j, cell in enumerate(row):
                if cell == '1':
                    islands += 1
                    self.remove_island(grid, i, j)
        return islands

    def remove_island(self, grid: List[List[str]], i: int, j: int) -> None:
        # Check out of bounds and not water
        if (i < 0) or (j < 0) or (i >= len(grid)) or (j >= len(grid[0])) or grid[i][j] == '0':
            return;
        grid[i][j] = '0' # Invalidate
        self.remove_island(grid, i, j - 1)  # left
        self.remove_island(grid, i, j + 1)  # right
        self.remove_island(grid, i - 1, j)  # up
        self.remove_island(grid, i + 1, j)  # down
        return 

