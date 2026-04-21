#include <stdlib.h>
#include <limits.h>

int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k) {
    int** graph = (int**)malloc((n + 1) * sizeof(int*));
    int* graphSize = (int*)calloc(n + 1, sizeof(int));

    for (int i = 1; i <= n; i++) {
        graph[i] = (int*)malloc(timesSize * 2 * sizeof(int));
    }

    for (int i = 0; i < timesSize; i++) {
        int u = times[i][0];
        int v = times[i][1];
        int w = times[i][2];

        int idx = graphSize[u];
        graph[u][idx] = v;
        graph[u][idx + 1] = w;
        graphSize[u] += 2;
    }

    int* dist = (int*)malloc((n + 1) * sizeof(int));
    int* visited = (int*)calloc(n + 1, sizeof(int));

    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    dist[k] = 0;

    for (int i = 1; i <= n; i++) {
        int u = -1;
        int minDist = INT_MAX;

        for (int j = 1; j <= n; j++) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }

        if (u == -1) break;

        visited[u] = 1;

        for (int j = 0; j < graphSize[u]; j += 2) {
            int v = graph[u][j];
            int w = graph[u][j + 1];

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    int maxTime = 0;

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX)
            return -1;
        if (dist[i] > maxTime)
            maxTime = dist[i];
    }

    for (int i = 1; i <= n; i++)
        free(graph[i]);
    free(graph);
    free(graphSize);
    free(dist);
    free(visited);

    return maxTime;
}