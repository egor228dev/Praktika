#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <locale.h>
#include <conio.h>
#include "algoritm1.h"
#include "design1.h"

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
        printf("������ �������� �����: %s\n", strerror(errno));
        system("pause");
        return 0;
    }

    char line[4096];
    if (!fgets(line, sizeof(line), file)) {
        fclose(file);
        printf("���� ���� ��� ������ ������\n");
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
            printf("������������ ������ � �����: %s\n", token);
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
        printf("������ �������� �����: %s\n", strerror(errno));
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
    printf("��������� ������� �������� � %s\n", filename);
    system("pause");
}

void create_example_csv(const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("������ �������� �����: %s\n", strerror(errno));
        system("pause");
        return;
    }

    fprintf(file, "5,3,8,1,2,7,4,6\n");
    fclose(file);
    printf("������ ����� ������: %s\n", filename);
    system("pause");
}

int system_sort() {
    int choice;
    char filename[256];
    while (1) {
        display_main_menu();

        if (scanf_s("%d", &choice) != 1) {
            printf("������������ ����. ����������, ������� �����.\n");
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
                    printf("������������ ����. ����������, ������� �����.\n");
                    clean_stdin();
                    system("pause");
                    continue;
                }

                switch (create_choice) {
                case 1:
                    printf("������� ������ ���� � ����� (��������, C:\\path\\to\\file.csv): ");
                    scanf_s("%s", filename, 255);
                    create_example_csv(filename);
                    break;
                case 2:
                    create_example_csv("input.csv");
                    break;
                case 3:
                    break;
                default:
                    printf("����������� �������. ���������� �����.\n");
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
                    printf("������������ ����. ����������, ������� �����.\n");
                    clean_stdin();
                    system("pause");
                    continue;
                }

                switch (load_choice) {
                case 1:
                    printf("������� ������ ���� � �����: ");
                    scanf_s("%s", filename, 255);
                    if (read_csv(filename)) {
                        printf("������ ������� ��������:\n");
                        print_array(array, array_size);
                    }
                    system("pause");
                    break;
                case 2:
                    if (read_csv("input.csv")) {
                        printf("������ ������� �������� �� input.csv:\n");
                        print_array(array, array_size);
                    }
                    else {
                        printf("���� input.csv �� ������ � �������� ����� �������.\n");
                    }
                    system("pause");
                    break;
                case 3:
                    break;
                default:
                    printf("����������� �������. ���������� �����.\n");
                    system("pause");
                    continue;
                }
                break;
            }
            break;
        }
        case 3: {
            if (array_size == 0) {
                printf("������ ����. ��������� ������ �������.\n");
            }
            else {
                selection_sort(array, array_size);
                printf("������ ������������:\n");
                print_array(array, array_size);
            }
            system("pause");
            break;
        }
        case 4: {
            if (array_size == 0) {
                printf("������ ����. ������ ���������.\n");
            }
            else {
                printf("������� ��� ����� ��� ����������: ");
                scanf_s("%s", filename, 255);
                write_csv(filename);
            }
            break;
        }
        case 5: {
            if (array_size == 0) {
                printf("������ ����.\n");
            }
            else {
                printf("������� ������:\n");
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
            printf("����� �� ���������.\n");
            return 0;
        }
        default: {
            printf("����������� �������. ���������� �����.\n");
            system("pause");
            break;
        }
        }
    }
}