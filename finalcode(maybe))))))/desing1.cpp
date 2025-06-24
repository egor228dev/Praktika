#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <locale.h>
#include <conio.h>
#include "design1.h"

extern int array[MAX_ARRAY_SIZE];
extern int array_size;

void print_array(const int arr[], int size) {
    printf("Текущий массив (%d элементов):\n", size);
    for (int i = 0; i < size; i++) {
        printf("[%d] = %d", i, arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
        if ((i + 1) % 5 == 0) printf("\n");
    }
    printf("\n");
}

void clean_stdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void display_main_menu() {
    system("cls");
    printf("Программа сортировки выбором (минимальные элементы в конец)\n");
    printf("--------------------------------------------------------\n");
    printf("\nМеню:\n");
    printf("1. Создать пример CSV файла\n");
    printf("2. Загрузить массив из CSV файла\n");
    printf("3. Отсортировать текущий массив\n");
    printf("4. Сохранить массив в CSV файл\n");
    printf("5. Показать текущий массив\n");
    printf("6. Редактировать массив\n");
    printf("7. Выход\n");
    printf("Выберите действие: ");
}

void display_create_example_menu() {
    system("cls");
    printf("Создание примера CSV файла\n");
    printf("--------------------------\n");
    printf("1. Создать в указанном месте (введите полный путь)\n");
    printf("2. Создать в корневой папке проекта (input.csv)\n");
    printf("3. Вернуться в главное меню\n");
    printf("Выберите действие: ");
}

void display_load_array_menu() {
    system("cls");
    printf("Загрузка массива из CSV файла\n");
    printf("----------------------------\n");
    printf("1. Указать путь к файлу\n");
    printf("2. Загрузить из корневой папки проекта (input.csv)\n");
    printf("3. Вернуться в главное меню\n");
    printf("Выберите действие: ");
}

void display_edit_array_menu() {
    system("cls");
    printf("Редактирование массива\n");
    printf("----------------------\n");
    printf("1. Добавить элемент\n");
    printf("2. Изменить элемент\n");
    printf("3. Удалить элемент\n");
    printf("4. Очистить массив\n");
    printf("5. Вернуться в главное меню\n");
    printf("Выберите действие: ");
}

void edit_array() {
    int choice, index, value;

    while (1) {
        system("cls");
        print_array(array, array_size);
        display_edit_array_menu();
        if (scanf_s("%d", &choice) != 1) {
            printf("Некорректный ввод. Пожалуйста, введите число.\n");
            clean_stdin();
            system("pause");
            continue;
        }

        switch (choice) {
        case 1:
            if (array_size >= MAX_ARRAY_SIZE) {
                printf("Массив полон! Невозможно добавить элемент.\n");
                system("pause");
                break;
            }
            printf("Введите значение нового элемента: ");
            if (scanf_s("%d", &value) != 1) {
                printf("Некорректный ввод.\n");
                clean_stdin();
            }
            else {
                array[array_size++] = value;
                printf("Элемент добавлен.\n");
            }
            system("pause");
            break;

        case 2:
            if (array_size == 0) {
                printf("Массив пуст! Невозможно изменить элемент.\n");
                system("pause");
                break;
            }
            printf("Введите индекс элемента (0-%d): ", array_size - 1);
            if (scanf_s("%d", &index) != 1 || index < 0 || index >= array_size) {
                printf("Некорректный индекс.\n");
                clean_stdin();
            }
            else {
                printf("Текущее значение: %d. Введите новое значение: ", array[index]);
                if (scanf_s("%d", &value) != 1) {
                    printf("Некорректный ввод.\n");
                    clean_stdin();
                }
                else {
                    array[index] = value;
                    printf("Элемент изменен.\n");
                }
            }
            system("pause");
            break;

        case 3:
            if (array_size == 0) {
                printf("Массив пуст! Невозможно удалить элемент.\n");
                system("pause");
                break;
            }
            printf("Введите индекс элемента для удаления (0-%d): ", array_size - 1);
            if (scanf_s("%d", &index) != 1 || index < 0 || index >= array_size) {
                printf("Некорректный индекс.\n");
                clean_stdin();
            }
            else {
                for (int i = index; i < array_size - 1; i++) {
                    array[i] = array[i + 1];
                }
                array_size--;
                printf("Элемент удален.\n");
            }
            system("pause");
            break;

        case 4:
            array_size = 0;
            printf("Массив очищен.\n");
            system("pause");
            break;

        case 5:
            return;

        default:
            printf("Неизвестная команда. Попробуйте снова.\n");
            system("pause");
            break;
        }
    }
}