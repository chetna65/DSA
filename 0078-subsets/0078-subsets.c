/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** g_result = NULL;
int* g_column_sizes = NULL;
int g_result_count = 0;
#define MAX_SUBSETS 1024 

void backtrack(int* nums, int numsSize, int index, int* current_subset, int subset_len) {
    int* final_subset = (int*)malloc(subset_len * sizeof(int));
    if (final_subset == NULL) return; 

    memcpy(final_subset, current_subset, subset_len * sizeof(int));

    if (g_result_count < MAX_SUBSETS) {
        g_result[g_result_count] = final_subset;
        g_column_sizes[g_result_count] = subset_len;
        g_result_count++;
    } else {
        free(final_subset);
        return; 
    }

    for (int i = index; i < numsSize; i++) {
        current_subset[subset_len] = nums[i];
        backtrack(nums, numsSize, i + 1, current_subset, subset_len + 1);
    }
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    
    g_result = (int**)malloc(MAX_SUBSETS * sizeof(int*));
    g_column_sizes = (int*)malloc(MAX_SUBSETS * sizeof(int));
    
    if (g_result == NULL || g_column_sizes == NULL) {
        if (g_result) free(g_result);
        if (g_column_sizes) free(g_column_sizes);
        *returnColumnSizes = NULL;
        return NULL;
    }

    g_result_count = 0;
    
    int* current_subset = (int*)malloc(numsSize * sizeof(int));
    if (current_subset == NULL) {
        free(g_result);
        free(g_column_sizes);
        *returnColumnSizes = NULL;
        return NULL;
    }

    backtrack(nums, numsSize, 0, current_subset, 0);

    free(current_subset);

    *returnSize = g_result_count;
    *returnColumnSizes = g_column_sizes;

    int** trimmed_result = (int**)realloc(g_result, g_result_count * sizeof(int*));
    if (trimmed_result) {
        g_result = trimmed_result;
    }
    
    return g_result;
}