#include <stdlib.h>

void backtrack(int* candidates, int candidatesSize, int target,
               int start, int* path, int pathSize,
               int*** result, int* returnSize, int* capacity,
               int** returnColumnSizes) {

    if (target == 0) {
        if (*returnSize >= *capacity) {
            *capacity *= 2;
            *result = realloc(*result, (*capacity) * sizeof(int*));
            *returnColumnSizes = realloc(*returnColumnSizes, (*capacity) * sizeof(int));
        }

        (*result)[*returnSize] = (int*)malloc(sizeof(int) * pathSize);
        (*returnColumnSizes)[*returnSize] = pathSize;

        for (int i = 0; i < pathSize; i++) {
            (*result)[*returnSize][i] = path[i];
        }

        (*returnSize)++;
        return;
    }

    for (int i = start; i < candidatesSize; i++) {
        if (candidates[i] > target) continue;

        path[pathSize] = candidates[i];

        backtrack(candidates, candidatesSize, target - candidates[i],
                  i, path, pathSize + 1,
                  result, returnSize, capacity, returnColumnSizes);
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target,
                     int* returnSize, int** returnColumnSizes) {

    int capacity = 100;
    int** result = (int**)malloc(sizeof(int*) * capacity);
    *returnColumnSizes = (int*)malloc(sizeof(int) * capacity);
    *returnSize = 0;

    int* path = (int*)malloc(sizeof(int) * target);

    backtrack(candidates, candidatesSize, target, 0,
              path, 0, &result, returnSize, &capacity, returnColumnSizes);

    free(path);
    return result;
}