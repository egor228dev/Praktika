#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARRAY_SIZE 1000

int array[MAX_ARRAY_SIZE];
int array_size = 0;

int read_csv(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Ошибка открытия файла: %s\n", strerror(errno));
        system("pause");
        return 0;
    }
}
void clean_stdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}
void display_create_example_menu() {
    system("cls");
    printf("Создание примера CSV файла\n");
    printf("--------------------------\n");
    printf("1. Создать в указанном месте (введите полный путь)\n");
    printf("2. Создать в корневой папке проекта (example.csv)\n");
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
        display_edit_array_menu();
        if (scanf_s("%d", &choice) != 1) {
            printf("Некорректный ввод. Пожалуйста, введите число.\n");
            clean_stdin();
            system("pause");
            continue;
        }

        switch (choice) {
        case 1: // Добавить элемент
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

        case 2: // Изменить элемент
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

        case 3: // Удалить элемент
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

        case 4: // Очистить массив
            array_size = 0;
            printf("Массив очищен.\n");
            system("pause");
            break;

        case 5: // Выход
            return;

        default:
            printf("Неизвестная команда. Попробуйте снова.\n");
            system("pause");
            break;
        }
    }
}

int system_sort() {
    int choice;
    char filename[256];
    while (1) {
        // TODO 155-166 вынести в отдельную функцию
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

        if (scanf_s("%d", &choice) != 1) {
            printf("Некорректный ввод. Пожалуйста, введите число.\n");
            clean_stdin();
            system("pause");
            continue;
        }

        switch (choice) {
        case 1: {
            int create_choice;
            while (1) {
                display_create_example_menu();
                // TODO переписать на switch-case
                if (scanf_s("%d", &create_choice) != 1) {
                    printf("Некорректный ввод. Пожалуйста, введите число.\n");
                    clean_stdin();
                    system("pause");
                    continue;
                }
                if (create_choice == 1) {
                    printf("Введите полный путь к файлу (например, C:\\path\\to\\file.csv): ");
                    scanf_s("%s", filename, 255);
                    break;
                }
                else if (create_choice == 2) {
                    break;
                }
                else if (create_choice == 3) {
                    break;
                }
                else {
                    printf("Неизвестная команда. Попробуйте снова.\n");
                    system("pause");
                }
            }
            break;
        }
        case 2: {
            int load_choice;
            while (1) {
                display_load_array_menu();
                // TODO переписать на switch-case
                if (scanf_s("%d", &load_choice) != 1) {
                    printf("Некорректный ввод. Пожалуйста, введите число.\n");
                    clean_stdin();
                    system("pause");
                    continue;
                }

                if (load_choice == 1) {
                    printf("Введите полный путь к файлу: ");
                    scanf_s("%s", filename, 255);
                    if (read_csv(filename)) {
                        printf("Массив успешно загружен:\n");
                    }
                    system("pause");
                    break;
                }
                else if (load_choice == 2) {
                    if (read_csv("input.csv")) {
                        printf("Массив успешно загружен из input.csv:\n");
                    }
                    else {
                        printf("Файл input.csv не найден в корневой папке проекта.\n");
                    }
                    system("pause");
                    break;
                }
                else if (load_choice == 3) {
                    break;
                }
                else {
                    printf("Неизвестная команда. Попробуйте снова.\n");
                    system("pause");
                }
            }
            break;
        }
        case 3: {
            if (array_size == 0) {
                printf("Массив пуст. Загрузите данные сначала.\n");
            }
            else {
                printf("Массив отсортирован:\n");
            }
            system("pause");
            break;
        }
        case 4: {
            if (array_size == 0) {
                printf("Массив пуст. Нечего сохранять.\n");
            }
            else {
                printf("Введите имя файла для сохранения: ");
                scanf_s("%s", filename, 255);
            }
            break;
        }
        case 5: {
            if (array_size == 0) {
                printf("Массив пуст.\n");
            }
            else {
                printf("Текущий массив:\n");
            }
            system("pause");
            break;
        }
        case 6: {
            edit_array();
            break;
        }
        case 7: {
            printf("Выход из программы.\n");
            return 0;
        }
        default: {
            printf("Неизвестная команда. Попробуйте снова.\n");
            system("pause");
            break;
        }
        }
    }
}
