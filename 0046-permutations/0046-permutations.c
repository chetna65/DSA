/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 int** g_result = NULL;
int* g_column_sizes = NULL;
int g_result_count = 0;
#define MAX_PERMUTATIONS 1000

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void backtrack(int* nums, int numsSize, int start) {
    if (start == numsSize) {
        int* current_perm = (int*)malloc(numsSize * sizeof(int));
        if (current_perm == NULL) return; 

        memcpy(current_perm, nums, numsSize * sizeof(int));

        if (g_result_count < MAX_PERMUTATIONS) {
            g_result[g_result_count] = current_perm;
            g_column_sizes[g_result_count] = numsSize;
            g_result_count++;
        } else {
            free(current_perm);
        }
        return;
    }

    for (int i = start; i < numsSize; i++) {
        swap(&nums[start], &nums[i]);
        backtrack(nums, numsSize, start + 1);
        swap(&nums[start], &nums[i]);
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    
    if (numsSize == 0) {
        *returnColumnSizes = NULL;
        return NULL;
    }

    g_result = (int**)malloc(MAX_PERMUTATIONS * sizeof(int*));
    g_column_sizes = (int*)malloc(MAX_PERMUTATIONS * sizeof(int));
    
    if (g_result == NULL || g_column_sizes == NULL) {
        if (g_result) free(g_result);
        if (g_column_sizes) free(g_column_sizes);
        return NULL;
    }

    g_result_count = 0;
    
    backtrack(nums, numsSize, 0);

    *returnSize = g_result_count;
    *returnColumnSizes = g_column_sizes;

    int** trimmed_result = (int**)realloc(g_result, g_result_count * sizeof(int*));
    if (trimmed_result) {
        g_result = trimmed_result;
    }
    
    return g_result;
}