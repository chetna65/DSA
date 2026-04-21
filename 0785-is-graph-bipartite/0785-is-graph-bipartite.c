bool isBipartite(int** graph, int graphSize, int* graphColSize) {
    int* color = (int*)malloc(sizeof(int) * graphSize);

    for (int i = 0; i < graphSize; i++)
        color[i] = -1;

    int* queue = (int*)malloc(sizeof(int) * graphSize);

    for (int i = 0; i < graphSize; i++) {
        if (color[i] != -1) continue;

        int front = 0, rear = 0;
        queue[rear++] = i;
        color[i] = 0;

        while (front < rear) {
            int node = queue[front++];

            for (int j = 0; j < graphColSize[node]; j++) {
                int nei = graph[node][j];

                if (color[nei] == -1) {
                    color[nei] = 1 - color[node];
                    queue[rear++] = nei;
                } else if (color[nei] == color[node]) {
                    free(color);
                    free(queue);
                    return false;
                }
            }
        }
    }

    free(color);
    free(queue);
    return true;
}