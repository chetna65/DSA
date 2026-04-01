typedef struct {
    char ch;
    int freq;
} Pair;

int compare(const void* a, const void* b) {
    Pair* p1 = (Pair*)a;
    Pair* p2 = (Pair*)b;
    return p2->freq - p1->freq;
}

char* frequencySort(char* s) {
    
    int freq[128] = {0};
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        freq[s[i]]++;
    }

    Pair arr[128];
    int size = 0;

    for (int i = 0; i < 128; i++) {
        if (freq[i] > 0) {
            arr[size].ch = (char)i;
            arr[size].freq = freq[i];
            size++;
        }
    }

    qsort(arr, size, sizeof(Pair), compare);

    char* result = (char*)malloc((len + 1) * sizeof(char));
    int index = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < arr[i].freq; j++) {
            result[index++] = arr[i].ch;
        }
    }

    result[index] = '\0';
    return result;
}