int lengthOfLongestSubstring(char* s) {
    
    int map[256];
    for (int i = 0; i < 256; i++) {
        map[i] = -1;
    }

    int maxLen = 0;
    int start = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        
        if (map[s[i]] >= start) {
            start = map[s[i]] + 1;
        }

        map[s[i]] = i;

        int currLen = i - start + 1;
        if (currLen > maxLen) {
            maxLen = currLen;
        }
    }

    return maxLen;
}