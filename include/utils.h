#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <ctype.h>

#define BUFFER_SIZE 5000
#define ARRAY_SIZE 3

typedef struct ReturnArray {
    int *array;
    int len;
} ReturnArray;

void check_max(int temp_value, int calories[]);
void file_parser(const char *filename);
void print_func(int calories[]);
void remove_chars(char *s, char c);

/*DAY 3*/
int get_result(char str[]);
char split_string(char str[]);
char find_character(char *s1, char *s2);

/*DAY 6*/
static const int size_1 = 4;
static const int size_2 = 14;

int get_result6(char str[BUFFER_SIZE], const int size);
char *get_substr(const int size);
int isUnique(char str[], const int size);

#endif