int absVal(int x) {
    return x < 0 ? -x : x;
}

int manhattanDist(int* p1, int* p2) {
    return absVal(p1[0] - p2[0]) + absVal(p1[1] - p2[1]);
}

int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize) {
    int n = pointsSize;
    int* minDist = (int*)malloc(sizeof(int) * n);
    bool* inMST = (bool*)malloc(sizeof(bool) * n);

    memset(inMST, 0, sizeof(bool) * n);  
    for (int i = 0; i < n; i++) {
        minDist[i] = INT_MAX;
    }

    int result = 0;
    minDist[0] = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;
        for (int j = 0; j < n; j++) {
            if (!inMST[j] && (u == -1 || minDist[j] < minDist[u])) {
                u = j;
            }
        }

        inMST[u] = true;
        result += minDist[u];

        for (int v = 0; v < n; v++) {
            if (!inMST[v]) {
                int dist = manhattanDist(points[u], points[v]);
                if (dist < minDist[v]) {
                    minDist[v] = dist;
                }
            }
        }
    }

    free(minDist);
    free(inMST);
    return result;
}