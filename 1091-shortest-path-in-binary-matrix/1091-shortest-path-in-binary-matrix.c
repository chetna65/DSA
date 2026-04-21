typedef struct {
    int x, y, dist;
} Node;

int shortestPathBinaryMatrix(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize;

    if (grid[0][0] != 0 || grid[n-1][n-1] != 0)
        return -1;

    int dirs[8][2] = {
        {1,0}, {-1,0}, {0,1}, {0,-1},
        {1,1}, {1,-1}, {-1,1}, {-1,-1}
    };

    Node* queue = (Node*)malloc(sizeof(Node) * n * n);
    int front = 0, rear = 0;

    queue[rear++] = (Node){0, 0, 1};
    grid[0][0] = 1;

    while (front < rear) {
        Node curr = queue[front++];

        if (curr.x == n - 1 && curr.y == n - 1)
            return curr.dist;

        for (int i = 0; i < 8; i++) {
            int nx = curr.x + dirs[i][0];
            int ny = curr.y + dirs[i][1];

            if (nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 0) {
                queue[rear++] = (Node){nx, ny, curr.dist + 1};
                grid[nx][ny] = 1;
            }
        }
    }

    return -1;
}