#include "menu.h"
#include "func.h"
#include "array.h"

void display_main_menu() {
    system("cls");
    printf("Программа сортировки выбором (минимальные элементы в конец)\n");
    printf("--------------------------------------------------------\n");
    printf("\nМеню:\n");
    printf("1. Создать пример CSV файла\n");
    printf("2. Загрузить массив из CSV файла\n");
    printf("3. Отсортировать текущий массив\n");
    printf("4. Сохранить массив в CSV файл\n");
    printf("5. Показать отсортированный массив\n");
    printf("6. Показать загруженный массив\n");
    printf("7. Редактировать массив\n");
    printf("8. Выход\n");
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

int system_sort() {
    int choice;
    char filename[256];
    srand(time(NULL));

    while (1) {
        display_main_menu();
        if (scanf_s("%d", &choice) != 1) {
            printf("Некорректный ввод. Введите число.\n");
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
                    printf("Некорректный ввод.\n");
                    clean_stdin();
                    system("pause");
                    continue;
                }

                if (create_choice == 1 || create_choice == 2) {
                    int size;
                    printf("Введите размер массива (1-%d): ", MAX_ARRAY_SIZE);
                    if (scanf_s("%d", &size) != 1 || size < 1 || size > MAX_ARRAY_SIZE) {
                        printf("Некорректный размер.\n");
                        clean_stdin();
                        system("pause");
                        continue;
                    }
                    if (create_choice == 1) {
                        printf("Введите путь к файлу: ");
                        scanf_s("%s", filename, 255);
                        create_example_csv(filename, size);
                    }
                    else {
                        create_example_csv("input.csv", size);
                    }
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
                    printf("Некорректный ввод.\n");
                    clean_stdin();
                    system("pause");
                    continue;
                }
                if (load_choice == 1) {
                    printf("Введите путь к файлу: ");
                    scanf_s("%s", filename, 255);
                    if (read_csv(filename)) print_array(array, array_size);
                }
                else if (load_choice == 2) {
                    if (read_csv("input.csv")) print_array(array, array_size);
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
                LARGE_INTEGER frequency, start, end;
                QueryPerformanceFrequency(&frequency);
                QueryPerformanceCounter(&start);

                int comparisons = selection_sort(array, array_size);

                QueryPerformanceCounter(&end);
                double time_spent = (double)(end.QuadPart - start.QuadPart) * 1000.0 / frequency.QuadPart;

                print_array(array, array_size);

                printf("Массив отсортирован.\n");
                printf("Количество переборов: %d\n", comparisons);
                if (time_spent < 0.001)
                    printf("Время сортировки: <0.001 мс\n");
                else
                    printf("Время сортировки: %.3f мс\n", time_spent);

                save_sorted_array();
            }
            system("pause");
            break;
        }
        case 4:
            if (array_size == 0)
                printf("Массив пуст.\n");
            else {
                printf("Введите имя файла: ");
                scanf_s("%s", filename, 255);
                write_csv(filename);
            }
            break;
        case 5:
            print_array_from_file("sorted.csv");
            system("pause");
            break;
        case 6:
            if (array_size == 0)
                printf("Массив пуст.\n");
            else
                print_array(array, array_size);
            system("pause");
            break;
        case 7:
            edit_array();
            break;
        case 8:
            return 0;
        default:
            printf("Неизвестная команда.\n");
            system("pause");
        }
    }
}