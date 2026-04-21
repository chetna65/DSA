int parent[26];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unionSet(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    if (pa != pb)
        parent[pa] = pb;
}

bool equationsPossible(char** equations, int equationsSize) {
    for (int i = 0; i < 26; i++)
        parent[i] = i;

    for (int i = 0; i < equationsSize; i++) {
        if (equations[i][1] == '=') {
            int a = equations[i][0] - 'a';
            int b = equations[i][3] - 'a';
            unionSet(a, b);
        }
    }

    for (int i = 0; i < equationsSize; i++) {
        if (equations[i][1] == '!') {
            int a = equations[i][0] - 'a';
            int b = equations[i][3] - 'a';
            if (find(a) == find(b))
                return false;
        }
    }

    return true;
}