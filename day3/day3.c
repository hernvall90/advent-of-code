#include "../include/utils.h"

int get_result(char str[])
{
    char ch = '\0';

    ch = split_string(str);

    if (isupper(ch)) {
        return (int) ch - 38;
    } else if (islower(ch)) {
        return (int) ch - 96;
    } else {
        return -1;
    }
}

char split_string(char str[])
{
    int len1 = strlen(str) / 2;
    int len2 = strlen(str) - len1;

    char *s1 = malloc((len1 + 1) * sizeof(char));
    memcpy(s1, str, len1);
    char *s2 = malloc((len2 + 1) * sizeof(char));
    memcpy(s2, str + len1, len2);
    s1[len1] = '\0', s2[len2] = '\0';

    return find_character(s1, s2); 
}

char find_character(char *s1, char *s2)
{
    int i = 0, j = 0;
    char ch = '\0';

    for (i = 0; i < (int) strlen(s1); i++) {
        for (j = 0; j < (int) strlen(s2); j++) {
            if (s1[i] == s2[j]) {
                ch = s1[i];
                goto abort;
            }
        }
    }

    free(s1);
    free(s2);
    return ch;
abort:
    free(s1);
    free(s2);
    return ch;
}

int main(void)
{
    const char *filename = "input.txt";
    char buffer[BUFFER_SIZE] = {'\0'};
    
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) { return -1; }

    int result = 0;

    while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
        result += get_result(buffer);
    }

    fclose(fp);
    printf("result=%d\n", result);

    return 0;
}