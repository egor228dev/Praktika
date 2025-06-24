#pragma once
#ifndef DESIGN_H
#define DESIGN_H

#include "algoritm1.h"  // Подключаем, чтобы получить MAX_ARRAY_SIZE

void print_array(const int arr[], int size);
void clean_stdin();
void display_main_menu();
void display_create_example_menu();
void display_load_array_menu();
void display_edit_array_menu();
void edit_array();

#endif
