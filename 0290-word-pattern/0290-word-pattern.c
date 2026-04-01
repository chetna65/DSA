bool wordPattern(char* pattern, char* s) {
    
    char* words[1000];
    int wordCount = 0;

    char* token = strtok(s, " ");
    while (token != NULL) {
        words[wordCount++] = token;
        token = strtok(NULL, " ");
    }

    int len = strlen(pattern);
    if (len != wordCount) return false;

    char* map[256] = {0};
    char* used[1000] = {0};

    for (int i = 0; i < len; i++) {
        char p = pattern[i];
        char* w = words[i];

        if (map[p] == NULL) {
            for (int j = 0; j < i; j++) {
                if (used[j] && strcmp(used[j], w) == 0) {
                    return false;
                }
            }
            map[p] = w;
            used[i] = w;
        } else {
            if (strcmp(map[p], w) != 0) {
                return false;
            }
        }
    }

    return true;
}