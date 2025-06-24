#pragma once
#ifndef ALGORITM_H
#define ALGORITM_H

#define MAX_ARRAY_SIZE 1000  // Переносим определение сюда

extern int array[MAX_ARRAY_SIZE];
extern int array_size;

void selection_sort(int arr[], int n);
int read_csv(const char* filename);
void write_csv(const char* filename);
void create_example_csv(const char* filename);
int system_sort();

#endif#pragma once
