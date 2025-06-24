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
    printf("������� ������ (%d ���������):\n", size);
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
    printf("��������� ���������� ������� (����������� �������� � �����)\n");
    printf("--------------------------------------------------------\n");
    printf("\n����:\n");
    printf("1. ������� ������ CSV �����\n");
    printf("2. ��������� ������ �� CSV �����\n");
    printf("3. ������������� ������� ������\n");
    printf("4. ��������� ������ � CSV ����\n");
    printf("5. �������� ������� ������\n");
    printf("6. ������������� ������\n");
    printf("7. �����\n");
    printf("�������� ��������: ");
}

void display_create_example_menu() {
    system("cls");
    printf("�������� ������� CSV �����\n");
    printf("--------------------------\n");
    printf("1. ������� � ��������� ����� (������� ������ ����)\n");
    printf("2. ������� � �������� ����� ������� (input.csv)\n");
    printf("3. ��������� � ������� ����\n");
    printf("�������� ��������: ");
}

void display_load_array_menu() {
    system("cls");
    printf("�������� ������� �� CSV �����\n");
    printf("----------------------------\n");
    printf("1. ������� ���� � �����\n");
    printf("2. ��������� �� �������� ����� ������� (input.csv)\n");
    printf("3. ��������� � ������� ����\n");
    printf("�������� ��������: ");
}

void display_edit_array_menu() {
    system("cls");
    printf("�������������� �������\n");
    printf("----------------------\n");
    printf("1. �������� �������\n");
    printf("2. �������� �������\n");
    printf("3. ������� �������\n");
    printf("4. �������� ������\n");
    printf("5. ��������� � ������� ����\n");
    printf("�������� ��������: ");
}

void edit_array() {
    int choice, index, value;

    while (1) {
        system("cls");
        print_array(array, array_size);
        display_edit_array_menu();
        if (scanf_s("%d", &choice) != 1) {
            printf("������������ ����. ����������, ������� �����.\n");
            clean_stdin();
            system("pause");
            continue;
        }

        switch (choice) {
        case 1:
            if (array_size >= MAX_ARRAY_SIZE) {
                printf("������ �����! ���������� �������� �������.\n");
                system("pause");
                break;
            }
            printf("������� �������� ������ ��������: ");
            if (scanf_s("%d", &value) != 1) {
                printf("������������ ����.\n");
                clean_stdin();
            }
            else {
                array[array_size++] = value;
                printf("������� ��������.\n");
            }
            system("pause");
            break;

        case 2:
            if (array_size == 0) {
                printf("������ ����! ���������� �������� �������.\n");
                system("pause");
                break;
            }
            printf("������� ������ �������� (0-%d): ", array_size - 1);
            if (scanf_s("%d", &index) != 1 || index < 0 || index >= array_size) {
                printf("������������ ������.\n");
                clean_stdin();
            }
            else {
                printf("������� ��������: %d. ������� ����� ��������: ", array[index]);
                if (scanf_s("%d", &value) != 1) {
                    printf("������������ ����.\n");
                    clean_stdin();
                }
                else {
                    array[index] = value;
                    printf("������� �������.\n");
                }
            }
            system("pause");
            break;

        case 3:
            if (array_size == 0) {
                printf("������ ����! ���������� ������� �������.\n");
                system("pause");
                break;
            }
            printf("������� ������ �������� ��� �������� (0-%d): ", array_size - 1);
            if (scanf_s("%d", &index) != 1 || index < 0 || index >= array_size) {
                printf("������������ ������.\n");
                clean_stdin();
            }
            else {
                for (int i = index; i < array_size - 1; i++) {
                    array[i] = array[i + 1];
                }
                array_size--;
                printf("������� ������.\n");
            }
            system("pause");
            break;

        case 4:
            array_size = 0;
            printf("������ ������.\n");
            system("pause");
            break;

        case 5:
            return;

        default:
            printf("����������� �������. ���������� �����.\n");
            system("pause");
            break;
        }
    }
}