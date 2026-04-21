#include <stdlib.h>
#include <string.h>

void backtrack(char** result, int* returnSize, char* curr, int pos,
               int open, int close, int n) {

    if (pos == 2 * n) {
        curr[pos] = '\0';
        result[*returnSize] = strdup(curr);
        (*returnSize)++;
        return;
    }

    if (open < n) {
        curr[pos] = '(';
        backtrack(result, returnSize, curr, pos + 1, open + 1, close, n);
    }

    if (close < open) {
        curr[pos] = ')';
        backtrack(result, returnSize, curr, pos + 1, open, close + 1, n);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    int capacity = 10000;
    char** result = (char**)malloc(sizeof(char*) * capacity);
    *returnSize = 0;

    char* curr = (char*)malloc(sizeof(char) * (2 * n + 1));

    backtrack(result, returnSize, curr, 0, 0, 0, n);

    free(curr);
    return result;
}