#include "array.h"
#include "func.h"

void edit_array() {
    int choice, index, value;

    while (1) {
        system("cls");
        print_array(array, array_size);
        display_edit_array_menu();
        if (scanf_s("%d", &choice) != 1) {
            printf("Некорректный ввод.\n");
            clean_stdin();
            system("pause");
            continue;
        }

        switch (choice) {
        case 1:
            if (array_size >= MAX_ARRAY_SIZE) {
                printf("Массив полон.\n");
            }
            else {
                printf("Введите значение: ");
                if (scanf_s("%d", &value) == 1) {
                    array[array_size++] = value;
                    reset_sorted_file();
                }
                else {
                    printf("Некорректный ввод.\n");
                    clean_stdin();
                }
            }
            break;
        case 2:
            printf("Введите индекс (0-%d): ", array_size - 1);
            if (scanf_s("%d", &index) == 1 && index >= 0 && index < array_size) {
                printf("Новое значение: ");
                if (scanf_s("%d", &value) == 1) {
                    array[index] = value;
                    reset_sorted_file();
                }
                else {
                    printf("Некорректный ввод.\n");
                    clean_stdin();
                }
            }
            else {
                printf("Некорректный индекс.\n");
                clean_stdin();
            }
            break;
        case 3:
            if (array_size == 0) {
                printf("Массив пуст.\n");
            }
            else {
                printf("Удалить элемент (0-%d): ", array_size - 1);
                if (scanf_s("%d", &index) == 1 && index >= 0 && index < array_size) {
                    for (int i = index; i < array_size - 1; i++)
                        array[i] = array[i + 1];
                    array_size--;
                    reset_sorted_file();
                }
                else {
                    printf("Некорректный индекс.\n");
                    clean_stdin();
                }
            }
            break;
        case 4:
            array_size = 0;
            reset_sorted_file();
            printf("Массив очищен.\n");
            break;
        case 5:
            return;
        default:
            printf("Неизвестная команда.\n");
        }
        system("pause");
    }
}