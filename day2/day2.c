#include "../include/utils.h"

typedef int (*return_order)(int opponent, int me);

int return_choice(char a)
{
    if (a == 'A' || a == 'X') {
        return 1;
    } else if (a == 'B' || a == 'Y') {
        return 2;
    } else if (a == 'C' || a == 'Z') {
        return 3;
    } else {
        return -1;
    }
}

int get_result(int opponent, int me, return_order order)
{   
    return order(opponent, me);
}

int part_one(int opponent, int me)
{
    if (opponent == me) {
        return me + 3;
    } else if (opponent == 1 && me == 3) {
        return me;
    } else if (opponent == 3 && me == 2) {
        return me;
    } else if (opponent == 2 && me == 1) {
        return me;
    } else {
        return me + 6;
    }
}

int part_two(int opponent, int me)
{
    switch (me) {
        case 1:
            if (opponent == 1) {
                return 3;
            }  else if (opponent == 2) {
                return 1;
            } else if (opponent == 3) {
                return 2;
            } else {
                return -1;
            }
            break;
        case 2:
            if (opponent == 1) {
                return 4;
            } else if (opponent == 2) {
                return 5;
            } else if (opponent == 3) {
                return 6;
            } else {
                return -1;
            }
            break;
        case 3:
            if (opponent == 1) {
                return 8;
            } else if (opponent == 2) {
                return 9;
            } else if (opponent == 3) {
                return 7;
            } else {
                return -1;
            }
            break;
        default:
            return -1;
    }
}

int main(void)
{
    const char *filename = "input.txt";
    char buffer[BUFFER_SIZE] = {'\0'};
    int result = 0;
    FILE *fp = fopen(filename, "r");

    while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
        // Part 1
        //result += get_result(return_choice(buffer[0]), return_choice(buffer[2]), part_one);
        // Part 2
        result += get_result(return_choice(buffer[0]), return_choice(buffer[2]), part_two);
    }

    printf("Part 1: total=%d\n", result);
    //printf("Part 2: total=%d\n", result);

    return 0;
}