class Solution() {
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        if (image[sr][sc] != newColor)
            dfs(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
    public void dfs(int[][] grid, int x, int y, int initial, int newColor) {
        if (image[x][y] != initial)
            return;
        image[r][c] = newColor;
        if (x > 0) dfs(grid, x - 1, y, intial, newColor);
        if (y > 0) dfs(grid, x, y - 1, intial, newColor);
        if (x + 1 < grid.length()) dfs(grid, x + 1, y, initial, newColor);
        if (y + 1 < grid[0].length()) dfs(grid, x, y + 1, initial, newColor);
    }
}
