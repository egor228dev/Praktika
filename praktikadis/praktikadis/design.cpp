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
        printf("������ �������� �����: %s\n", strerror(errno));
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
    printf("�������� ������� CSV �����\n");
    printf("--------------------------\n");
    printf("1. ������� � ��������� ����� (������� ������ ����)\n");
    printf("2. ������� � �������� ����� ������� (example.csv)\n");
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
        display_edit_array_menu();
        if (scanf_s("%d", &choice) != 1) {
            printf("������������ ����. ����������, ������� �����.\n");
            clean_stdin();
            system("pause");
            continue;
        }

        switch (choice) {
        case 1: // �������� �������
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

        case 2: // �������� �������
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

        case 3: // ������� �������
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

        case 4: // �������� ������
            array_size = 0;
            printf("������ ������.\n");
            system("pause");
            break;

        case 5: // �����
            return;

        default:
            printf("����������� �������. ���������� �����.\n");
            system("pause");
            break;
        }
    }
}

int system_sort() {
    int choice;
    char filename[256];
    while (1) {
        // TODO 155-166 ������� � ��������� �������
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
                // TODO ���������� �� switch-case
                if (scanf_s("%d", &create_choice) != 1) {
                    printf("������������ ����. ����������, ������� �����.\n");
                    clean_stdin();
                    system("pause");
                    continue;
                }
                if (create_choice == 1) {
                    printf("������� ������ ���� � ����� (��������, C:\\path\\to\\file.csv): ");
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
                    printf("����������� �������. ���������� �����.\n");
                    system("pause");
                }
            }
            break;
        }
        case 2: {
            int load_choice;
            while (1) {
                display_load_array_menu();
                // TODO ���������� �� switch-case
                if (scanf_s("%d", &load_choice) != 1) {
                    printf("������������ ����. ����������, ������� �����.\n");
                    clean_stdin();
                    system("pause");
                    continue;
                }

                if (load_choice == 1) {
                    printf("������� ������ ���� � �����: ");
                    scanf_s("%s", filename, 255);
                    if (read_csv(filename)) {
                        printf("������ ������� ��������:\n");
                    }
                    system("pause");
                    break;
                }
                else if (load_choice == 2) {
                    if (read_csv("input.csv")) {
                        printf("������ ������� �������� �� input.csv:\n");
                    }
                    else {
                        printf("���� input.csv �� ������ � �������� ����� �������.\n");
                    }
                    system("pause");
                    break;
                }
                else if (load_choice == 3) {
                    break;
                }
                else {
                    printf("����������� �������. ���������� �����.\n");
                    system("pause");
                }
            }
            break;
        }
        case 3: {
            if (array_size == 0) {
                printf("������ ����. ��������� ������ �������.\n");
            }
            else {
                printf("������ ������������:\n");
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
            }
            break;
        }
        case 5: {
            if (array_size == 0) {
                printf("������ ����.\n");
            }
            else {
                printf("������� ������:\n");
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
