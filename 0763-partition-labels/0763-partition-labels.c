/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* partitionLabels(char* s, int* returnSize) {
    int last[26] = {0};
    int len = 0;

    while (s[len] != '\0') {
        last[s[len] - 'a'] = len;
        len++;
    }

    int* result = (int*)malloc(sizeof(int) * len);
    int size = 0;

    int start = 0, end = 0;

    for (int i = 0; i < len; i++) {
        if (last[s[i] - 'a'] > end) {
            end = last[s[i] - 'a'];
        }

        if (i == end) {
            result[size++] = end - start + 1;
            start = i + 1;
        }
    }

    *returnSize = size;
    return result;
}