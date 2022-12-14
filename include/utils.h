#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <ctype.h>

#define BUFFER_SIZE 50
#define ARRAY_SIZE 3


void check_max(int temp_value, int calories[]);
void file_parser(const char *filename);
void print_func(int calories[]);
void remove_chars(char *s, char c);

/*DAY 3*/
int get_result(char str[]);
char split_string(char str[]);
char find_character(char *s1, char *s2);

#endif