#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <locale.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

#define MAX_ARRAY_SIZE 65536

extern int array[MAX_ARRAY_SIZE];
extern int array_size;
extern const char* sorted_filename;

void clean_stdin();