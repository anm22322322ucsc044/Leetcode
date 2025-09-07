char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";
    static char prefix[201];
    strcpy(prefix, strs[0]);

    for (int i = 1; i < strsSize; i++) {
        int j = 0;
        while (prefix[j] && strs[i][j] && prefix[j] == strs[i][j]) {
            j++;
        }
        prefix[j] = '\0';
        if (prefix[0] == '\0') return "";
    }
    return prefix;
}
