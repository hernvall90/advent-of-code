#include "../../include/utils.h"

int get_priority(char str[ARRAY_SIZE][BUFFER_SIZE])
{
    int i = 0, m = 0, n = 0, j = 65, size = 26;
    char ch = '\0';

    while (j < j + size) {
        for (i = 0; i < (int) strlen(str[0]); i++) {
            if (str[0][i] == (char) j) {
                for (m = 0; m < (int) strlen(str[1]); m++) {
                    if (str[1][m] == (char) j) {
                        for (n = 0; n < (int) strlen(str[2]); n++) {
                            if (str[2][n] == (char) j) {
                                ch = (char) j;
                                goto exit_condition;
                            }
                        }
                    }
                }
            }
        }
        j++;
    }

exit_condition:
    return (isupper(ch) ? (int) ch - 38 : (int) ch - 96);
}

int main(void)
{
    const char *filename = "input.txt";
    char buffer[BUFFER_SIZE] = {'\0'};
    char group[ARRAY_SIZE][BUFFER_SIZE];

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) { return -1; }

    int count = 0, result = 0;

    while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
         if (count <= ARRAY_SIZE - 1) {
            strcpy(group[count], buffer);
            
            if (count == ARRAY_SIZE - 1) {
                count = 0;
                result += get_priority(group);
            } else {
                count++;
            }
         }
    }

    fclose(fp);

    printf("%d\n", result);
 
    return 0;
}