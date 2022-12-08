#include "utils.h"

void check_max(int temp_value, int calories[])
{
    int i = 0, swap = 0;
    for(i = 0; i < ARRAY_SIZE; i++) {
        if (temp_value > calories[i]) {
            swap = calories[i];
            calories[i] = temp_value;
            temp_value = swap;
        }
    }
}

void file_parser(const char *filename)
{
    char buffer[BUFFER_SIZE];
    int calories[ARRAY_SIZE] = {0};
    int tmp = 0;
    
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        const char *message = "Failed to open file.";
        if (errno) {
            perror(message);
        } else {
            printf("ERROR: %s\n", message);
        }
        exit(1);
    }

    while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
        if (*buffer != '\n') {
            strtok(buffer, "\n");
            tmp += atoi(buffer);
        } else if (*buffer == '\n'){
            check_max(tmp, calories);
            tmp = 0;
        }
    }

    print_func(calories);

}

void print_func(int calories[])
{
    // Part 1:
    printf("Max value is: %d\n", calories[0]);
    // Part 2:
    printf("Top three elves are carrying %d calories in total.\n", calories[0] + calories[1] + calories[2]);
}

int main(void)
{
    const char *filename = "input.txt";
    file_parser(filename);
    return 0;
}