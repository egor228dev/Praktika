#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <locale.h>
#include <conio.h>

#define MAX_ARRAY_SIZE 1000

int array[MAX_ARRAY_SIZE];
int array_size = 0;

void selection_sort(int arr[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int min_idx = 0;
        for (int j = 1; j <= i; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int read_csv(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Ошибка открытия файла: %s\n", strerror(errno));
        system("pause");
        return 0;
    }

    char line[4096];
    if (!fgets(line, sizeof(line), file)) {
        fclose(file);
        printf("Файл пуст или ошибка чтения\n");
        system("pause");
        return 0;
    }

    char* token = strtok(line, ",");
    array_size = 0;

    while (token != NULL && array_size < MAX_ARRAY_SIZE) {
        char* endptr;
        long num = strtol(token, &endptr, 10);

        if (*endptr != '\0' && *endptr != '\n' && *endptr != '\r') {
            fclose(file);
            printf("Некорректные данные в файле: %s\n", token);
            system("pause");
            return 0;
        }

        array[array_size++] = (int)num;
        token = strtok(NULL, ",");
    }

    fclose(file);
    return 1;
}

void write_csv(const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Ошибка создания файла: %s\n", strerror(errno));
        system("pause");
        return;
    }

    for (int i = 0; i < array_size; i++) {
        fprintf(file, "%d", array[i]);
        if (i < array_size - 1) {
            fprintf(file, ",");
        }
    }
    fprintf(file, "\n");

    fclose(file);
    printf("Результат успешно сохранен в %s\n", filename);
    system("pause");
}

void create_example_csv(const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Ошибка создания файла: %s\n", strerror(errno));
        system("pause");
        return;
    }

    fprintf(file, "5,3,8,1,2,7,4,6\n");
    fclose(file);
    printf("Пример файла создан: %s\n", filename);
    system("pause");
}

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

int system_sort() {
    int choice;
    char filename[256];
    while (1) {
        display_main_menu();

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
                if (scanf_s("%d", &create_choice) != 1) {
                    printf("Некорректный ввод. Пожалуйста, введите число.\n");
                    clean_stdin();
                    system("pause");
                    continue;
                }

                switch (create_choice) {
                case 1:
                    printf("Введите полный путь к файлу (например, C:\\path\\to\\file.csv): ");
                    scanf_s("%s", filename, 255);
                    create_example_csv(filename);
                    break;
                case 2:
                    create_example_csv("input.csv");
                    break;
                case 3:
                    break;
                default:
                    printf("Неизвестная команда. Попробуйте снова.\n");
                    system("pause");
                    continue;
                }
                break;
            }
            break;
        }
        case 2: {
            int load_choice;
            while (1) {
                display_load_array_menu();
                if (scanf_s("%d", &load_choice) != 1) {
                    printf("Некорректный ввод. Пожалуйста, введите число.\n");
                    clean_stdin();
                    system("pause");
                    continue;
                }

                switch (load_choice) {
                case 1:
                    printf("Введите полный путь к файлу: ");
                    scanf_s("%s", filename, 255);
                    if (read_csv(filename)) {
                        printf("Массив успешно загружен:\n");
                        print_array(array, array_size);
                    }
                    system("pause");
                    break;
                case 2:
                    if (read_csv("input.csv")) {
                        printf("Массив успешно загружен из input.csv:\n");
                        print_array(array, array_size);
                    }
                    else {
                        printf("Файл input.csv не найден в корневой папке проекта.\n");
                    }
                    system("pause");
                    break;
                case 3:
                    break;
                default:
                    printf("Неизвестная команда. Попробуйте снова.\n");
                    system("pause");
                    continue;
                }
                break;
            }
            break;
        }
        case 3: {
            if (array_size == 0) {
                printf("Массив пуст. Загрузите данные сначала.\n");
            }
            else {
                selection_sort(array, array_size);
                printf("Массив отсортирован:\n");
                print_array(array, array_size);
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
                write_csv(filename);
            }
            break;
        }
        case 5: {
            if (array_size == 0) {
                printf("Массив пуст.\n");
            }
            else {
                printf("Текущий массив:\n");
                print_array(array, array_size);
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

int main() {
    setlocale(LC_ALL, "Rus");
    system_sort();
    return 0;
}