#pragma once
#include "common.h"

void reset_sorted_file();
int selection_sort(int arr[], int n);
int read_csv(const char* filename);
void write_csv(const char* filename);
void create_example_csv(const char* filename, int size);
void print_array_from_file(const char* filename);
void print_array(const int arr[], int size);
void save_sorted_array();