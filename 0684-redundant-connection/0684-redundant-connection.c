/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int parent[1001];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    for (int i = 1; i <= edgesSize; i++)
        parent[i] = i;

    int* result = (int*)malloc(sizeof(int) * 2);

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        int pu = find(u);
        int pv = find(v);

        if (pu == pv) {
            result[0] = u;
            result[1] = v;
        } else {
            parent[pu] = pv;
        }
    }

    *returnSize = 2;
    return result;
}