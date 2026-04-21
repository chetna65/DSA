#include <stdlib.h>
#include <string.h>

int isPalindrome(char* s, int l, int r) {
    while (l < r) {
        if (s[l++] != s[r--]) return 0;
    }
    return 1;
}

void backtrack(char* s, int start, int len,
               char**** result, int* returnSize, int* capacity,
               int** returnColumnSizes,
               char** path, int pathSize) {

    if (start == len) {
        if (*returnSize >= *capacity) {
            *capacity *= 2;
            *result = realloc(*result, (*capacity) * sizeof(char**));
            *returnColumnSizes = realloc(*returnColumnSizes, (*capacity) * sizeof(int));
        }

        (*result)[*returnSize] = (char**)malloc(sizeof(char*) * pathSize);
        (*returnColumnSizes)[*returnSize] = pathSize;

        for (int i = 0; i < pathSize; i++) {
            (*result)[*returnSize][i] = strdup(path[i]);
        }

        (*returnSize)++;
        return;
    }

    for (int end = start; end < len; end++) {
        if (isPalindrome(s, start, end)) {
            int subLen = end - start + 1;

            char* substr = (char*)malloc(subLen + 1);
            strncpy(substr, s + start, subLen);
            substr[subLen] = '\0';

            path[pathSize] = substr;

            backtrack(s, end + 1, len, result, returnSize, capacity,
                      returnColumnSizes, path, pathSize + 1);

            free(substr);
        }
    }
}

char*** partition(char* s, int* returnSize, int** returnColumnSizes) {
    int len = strlen(s);

    int capacity = 100;
    char*** result = (char***)malloc(sizeof(char**) * capacity);
    *returnColumnSizes = (int*)malloc(sizeof(int) * capacity);
    *returnSize = 0;

    char** path = (char**)malloc(sizeof(char*) * len);

    backtrack(s, 0, len, &result, returnSize, &capacity,
              returnColumnSizes, path, 0);

    free(path);
    return result;
}