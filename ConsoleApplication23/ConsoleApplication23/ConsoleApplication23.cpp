#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <locale.h>
#include <conio.h>
#include <windows.h>
        case 3: {
            if (array_size == 0) {
                printf("Массив пуст. Загрузите данные сначала.\n");
            }
            else {
                LARGE_INTEGER start, end, freq;
                QueryPerformanceFrequency(&freq); 
                QueryPerformanceCounter(&start);  
                selection_sort(array, array_size); 
                QueryPerformanceCounter(&end);    
                double time_spent = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;
                printf("Время сортировки: %.9f сек\n", time_spent);
                printf("Время сортировки: %.9f сек\n", time_spent);
                printf("Массив отсортирован:\n");
                print_array(array, array_size);
            }
