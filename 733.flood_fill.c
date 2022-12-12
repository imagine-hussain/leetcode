
void dfs(int **grid, int x, int y, int pre_replace, int post_replace)
{
    if ()
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** floodFill(
    int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes
){
    if (image[sr][sc] == color)
        return image;

    dfs(image, sr, sc, image[sr][sc], color);
    return image;
}


