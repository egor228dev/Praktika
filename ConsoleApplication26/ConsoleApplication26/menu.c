#include "menu.h"
#include "func.h"
#include "array.h"

void display_main_menu() {
    system("cls");
    printf("��������� ���������� ������� (����������� �������� � �����)\n");
    printf("--------------------------------------------------------\n");
    printf("\n����:\n");
    printf("1. ������� ������ CSV �����\n");
    printf("2. ��������� ������ �� CSV �����\n");
    printf("3. ������������� ������� ������\n");
    printf("4. ��������� ������ � CSV ����\n");
    printf("5. �������� ��������������� ������\n");
    printf("6. �������� ����������� ������\n");
    printf("7. ������������� ������\n");
    printf("8. �����\n");
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

int system_sort() {
    int choice;
    char filename[256];
    srand(time(NULL));

    while (1) {
        display_main_menu();
        if (scanf_s("%d", &choice) != 1) {
            printf("������������ ����. ������� �����.\n");
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
                    printf("������������ ����.\n");
                    clean_stdin();
                    system("pause");
                    continue;
                }

                if (create_choice == 1 || create_choice == 2) {
                    int size;
                    printf("������� ������ ������� (1-%d): ", MAX_ARRAY_SIZE);
                    if (scanf_s("%d", &size) != 1 || size < 1 || size > MAX_ARRAY_SIZE) {
                        printf("������������ ������.\n");
                        clean_stdin();
                        system("pause");
                        continue;
                    }
                    if (create_choice == 1) {
                        printf("������� ���� � �����: ");
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
                    printf("������������ ����.\n");
                    clean_stdin();
                    system("pause");
                    continue;
                }
                if (load_choice == 1) {
                    printf("������� ���� � �����: ");
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
                printf("������ ����. ��������� ������ �������.\n");
            }
            else {
                LARGE_INTEGER frequency, start, end;
                QueryPerformanceFrequency(&frequency);
                QueryPerformanceCounter(&start);

                int comparisons = selection_sort(array, array_size);

                QueryPerformanceCounter(&end);
                double time_spent = (double)(end.QuadPart - start.QuadPart) * 1000.0 / frequency.QuadPart;

                print_array(array, array_size);

                printf("������ ������������.\n");
                printf("���������� ���������: %d\n", comparisons);
                if (time_spent < 0.001)
                    printf("����� ����������: <0.001 ��\n");
                else
                    printf("����� ����������: %.3f ��\n", time_spent);

                save_sorted_array();
            }
            system("pause");
            break;
        }
        case 4:
            if (array_size == 0)
                printf("������ ����.\n");
            else {
                printf("������� ��� �����: ");
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
                printf("������ ����.\n");
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
            printf("����������� �������.\n");
            system("pause");
        }
    }
}