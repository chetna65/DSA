#include <stdlib.h>

int dfs(int** grid, int m, int n, int x, int y, int remain) {
    if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == -1)
        return 0;

    if (grid[x][y] == 2)
        return (remain == 1) ? 1 : 0;

    int temp = grid[x][y];
    grid[x][y] = -1;

    int paths = 0;

    paths += dfs(grid, m, n, x + 1, y, remain - 1);
    paths += dfs(grid, m, n, x - 1, y, remain - 1);
    paths += dfs(grid, m, n, x, y + 1, remain - 1);
    paths += dfs(grid, m, n, x, y - 1, remain - 1);

    grid[x][y] = temp;

    return paths;
}

int uniquePathsIII(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize, n = gridColSize[0];
    int startX = 0, startY = 0, count = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] != -1)
                count++;
            if (grid[i][j] == 1) {
                startX = i;
                startY = j;
            }
        }
    }

    return dfs(grid, m, n, startX, startY, count);
}