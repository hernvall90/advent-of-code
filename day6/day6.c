#include "../include/utils.h"

int isUnique(char str[], const int size)
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (str[i] == str[j]) {
                return -1;
            }
        }
    }

    return 1;
}

char *get_substr(const int size) 
{
    int i = 0;
    char *substr = malloc((size + 1) * sizeof(char));
    
    for (i = 0; i < size; i++) {
        substr[i] = '\0';
    }

    return substr;
}

int get_result6(char str[BUFFER_SIZE], const int size)
{
    char *substr = malloc((size + 1) * sizeof(char));
    int result = 0, count = size;
    size_t i = 0;

    while (i < strlen(str) - size) {
        strncpy(substr, str + i, size * sizeof(char));
        result = isUnique(substr, size);

        if (result == - 1) {
            count ++;
        } else if (result == 1) {
            break;
        }
        i++;
    }
    free(substr);

    return count;
}

int main(void)
{
    const char *filename = "input.txt";
    char buffer[BUFFER_SIZE] = { '\0' };
    int part1 = 0, part2 = 0;

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) return -1;

    while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
        part1 = get_result6(buffer, size_1);
        part2 = get_result6(buffer, size_2);
    }
    printf("part 1 = %d\n", part1);
    printf("part 2 = %d\n", part2);

    return 0;
}