void backtrack(int row, int n,
               char** board,
               int* col, int* diag1, int* diag2,
               char**** result, int* returnSize, int* capacity,
               int** returnColumnSizes) {

    if (row == n) {
        if (*returnSize >= *capacity) {
            *capacity *= 2;
            *result = realloc(*result, (*capacity) * sizeof(char**));
            *returnColumnSizes = realloc(*returnColumnSizes, (*capacity) * sizeof(int));
        }

        (*result)[*returnSize] = (char**)malloc(sizeof(char*) * n);
        (*returnColumnSizes)[*returnSize] = n;

        for (int i = 0; i < n; i++) {
            (*result)[*returnSize][i] = strdup(board[i]);
        }

        (*returnSize)++;
        return;
    }

    for (int j = 0; j < n; j++) {
        if (col[j] || diag1[row + j] || diag2[row - j + n - 1])
            continue;

        board[row][j] = 'Q';
        col[j] = diag1[row + j] = diag2[row - j + n - 1] = 1;

        backtrack(row + 1, n, board, col, diag1, diag2,
                  result, returnSize, capacity, returnColumnSizes);

        board[row][j] = '.';
        col[j] = diag1[row + j] = diag2[row - j + n - 1] = 0;
    }
}

char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {
    int capacity = 100;
    char*** result = (char***)malloc(sizeof(char**) * capacity);
    *returnColumnSizes = (int*)malloc(sizeof(int) * capacity);
    *returnSize = 0;

    char** board = (char**)malloc(sizeof(char*) * n);
    for (int i = 0; i < n; i++) {
        board[i] = (char*)malloc(n + 1);
        memset(board[i], '.', n);
        board[i][n] = '\0';
    }

    int* col = (int*)calloc(n, sizeof(int));
    int* diag1 = (int*)calloc(2 * n, sizeof(int));
    int* diag2 = (int*)calloc(2 * n, sizeof(int));

    backtrack(0, n, board, col, diag1, diag2,
              &result, returnSize, &capacity, returnColumnSizes);

    for (int i = 0; i < n; i++) free(board[i]);
    free(board);
    free(col);
    free(diag1);
    free(diag2);

    return result;
}