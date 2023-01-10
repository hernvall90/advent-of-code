#include "../include/utils.h"

int main(void)
{
    const char *filename = "test.txt";
    char buffer[BUFFER_SIZE] = { '\0' };
    int n1 = 0, n2 = 0, n3 = 0;

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) return -1;

    /*
    while (fscanf(fp, "move %d from %d to %d ", &n1, &n2, &n3) != EOF) {
        printf("d1=%d\td2=%d\td3=%d\n", n1, n2, n3);
    }
    */
    fclose(fp);


    return 0;
}