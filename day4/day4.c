#include "../include/utils.h"

typedef int (*array_compare)(ReturnArray *arr1, ReturnArray *arr2);

ReturnArray *return_array(int x, int y) {

    ReturnArray *return_array = malloc(sizeof(ReturnArray));
    return_array->len = (y - x) + 1;
    return_array->array = malloc(return_array->len * sizeof(int));

    for (int i = 0; i < return_array->len; i++, x++) {
        return_array->array[i] = x;
    }

    return return_array;
}

int isSubset(ReturnArray *arr1, ReturnArray *arr2)
{
    int i = 0, j = 0;

    while (i < arr1->len && j < arr2->len) {
        if (arr1->array[i] == arr2->array[j]) {
            i++;
            j++;

            if (j == arr2->len) {
                return 1;
            }
        } else {
            i = i - j + 1;
            j = 0;
        }
    }
    return 0;
}

int isOverlap(ReturnArray *arr1, ReturnArray *arr2)
{
    int i = 0, j = 0;

    for (i = 0; i < arr1->len; i++) {
        for (j = 0; j < arr2->len; j++) {
            if (arr1->array[i] == arr2->array[j]) {
                goto exit_condition;
            }
        }
    }

    return 0;
exit_condition:
    return 1;
}

int get_result4(int numbers[], array_compare compare) {
    
    ReturnArray *arr1 = return_array(numbers[0], numbers[1]);
    ReturnArray *arr2 = return_array(numbers[2], numbers[3]);

    int result = 0;

    result = (arr1->len > arr2->len) ? compare(arr1, arr2) : compare(arr2, arr1);

    free(arr1->array);
    free(arr1);
    free(arr2->array);
    free(arr2);

    return result;
}

int main(void)
{
    const char *filename = "input.txt";
    int numbers[ARRAY_SIZE + 1] = { 0 };
    
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) return -1;

    int part1 = 0, part2 = 0;

    while (fscanf(fp, "%d-%d,%d-%d ", &numbers[0], &numbers[1], &numbers[2], &numbers[3]) != EOF) {
        part1 += get_result4(numbers, isSubset);
        part2 += get_result4(numbers, isOverlap);
    }

    printf("Part 1, result=%d\n", part1);
    printf("Part 2, result=%d\n", part2);
    return 0;
}