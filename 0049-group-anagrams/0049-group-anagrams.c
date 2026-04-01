/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int compare(const void* a, const void* b) {
    return (*(char*)a - *(char*)b);
}

char* sortString(const char* str) {
    int len = strlen(str);
    char* sorted = (char*)malloc((len + 1) * sizeof(char));
    strcpy(sorted, str);
    qsort(sorted, len, sizeof(char), compare);
    return sorted;
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    
    char*** result = (char***)malloc(strsSize * sizeof(char**));
    *returnColumnSizes = (int*)malloc(strsSize * sizeof(int));
    
    char** keys = (char**)malloc(strsSize * sizeof(char*));
    int groupCount = 0;

    for (int i = 0; i < strsSize; i++) {
        char* sorted = sortString(strs[i]);
        
        int found = -1;

        for (int j = 0; j < groupCount; j++) {
            if (strcmp(keys[j], sorted) == 0) {
                found = j;
                break;
            }
        }

        if (found == -1) {
            keys[groupCount] = sorted;
            result[groupCount] = (char**)malloc(strsSize * sizeof(char*));
            result[groupCount][0] = strs[i];
            (*returnColumnSizes)[groupCount] = 1;
            groupCount++;
        } else {
            int idx = (*returnColumnSizes)[found];
            result[found][idx] = strs[i];
            (*returnColumnSizes)[found]++;
            free(sorted);
        }
    }

    *returnSize = groupCount;
    return result;
}