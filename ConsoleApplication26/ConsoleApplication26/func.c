#include "func.h"

int array[MAX_ARRAY_SIZE];
int array_size = 0;
const char* sorted_filename = "sorted.csv";

void reset_sorted_file() {
    FILE* file = fopen(sorted_filename, "w");
    if (file) fclose(file);
}

int selection_sort(int arr[], int n) {
    int comparisons = 0;
    for (int i = n - 1; i > 0; i--) {
        int min_idx = 0;
        for (int j = 1; j <= i; j++) {
            comparisons++;
            if (arr[j] < arr[min_idx]) min_idx = j;
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
    return comparisons;
}

int read_csv(const char* filename) {
    if (strcmp(filename, sorted_filename) == 0) {
        printf("Ошибка: нельзя загружать файл %s напрямую\n", sorted_filename);
        system("pause");
        return 0;
    }

    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Ошибка открытия файла: %s\n", strerror(errno));
        system("pause");
        return 0;
    }

    char line[262144];
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
    reset_sorted_file();
    return 1;
}

void write_csv(const char* filename) {
    if (strcmp(filename, sorted_filename) == 0) {
        printf("Ошибка: нельзя сохранять в файл %s напрямую\n", sorted_filename);
        system("pause");
        return;
    }

    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Ошибка создания файла: %s\n", strerror(errno));
        system("pause");
        return;
    }

    for (int i = 0; i < array_size; i++) {
        fprintf(file, "%d", array[i]);
        if (i < array_size - 1) fprintf(file, ",");
    }
    fprintf(file, "\n");

    fclose(file);
    printf("Результат успешно сохранен в %s\n", filename);
    system("pause");
}

void create_example_csv(const char* filename, int size) {
    if (strcmp(filename, sorted_filename) == 0) {
        printf("Ошибка: нельзя создать файл с именем %s\n", sorted_filename);
        system("pause");
        return;
    }

    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Ошибка создания файла: %s\n", strerror(errno));
        system("pause");
        return;
    }

    for (int i = 0; i < size; i++) {
        int num = (rand() % 201) - 100;
        fprintf(file, "%d", num);
        if (i < size - 1) fprintf(file, ",");
    }
    fprintf(file, "\n");

    fclose(file);
    reset_sorted_file();
    printf("Пример файла с %d случайными элементами создан: %s\n", size, filename);
    system("pause");
}

void print_array_from_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Массив не был отсортирован\n");
        return;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    if (size == 0) {
        printf("Массив не был отсортирован\n");
        fclose(file);
        return;
    }
    fseek(file, 0, SEEK_SET);

    char line[4096];
    if (!fgets(line, sizeof(line), file)) {
        printf("Массив не был отсортирован\n");
        fclose(file);
        return;
    }

    printf("Отсортированный массив из файла %s:\n", filename);
    char* token = strtok(line, ",");
    int index = 0;
    while (token != NULL) {
        char* endptr;
        long num = strtol(token, &endptr, 10);
        if (*endptr != '\0' && *endptr != '\n' && *endptr != '\r') {
            printf("Ошибка формата данных в файле\n");
            break;
        }
        printf("[%d] = %d", index++, (int)num);
        token = strtok(NULL, ",");
        if (token) printf(", ");
        if (index % 5 == 0) printf("\n");
    }
    printf("\n");

    fclose(file);
}

void print_array(const int arr[], int size) {
    printf("%d элементов\n", size);
    for (int i = 0; i < size; i++) {
        printf("[%d] = %d", i, arr[i]);
        if (i < size - 1) printf(", ");
        if ((i + 1) % 5 == 0) printf("\n");
    }
    printf("\n");
}

void save_sorted_array() {
    FILE* file = fopen(sorted_filename, "w");
    if (!file) {
        printf("Ошибка создания файла %s: %s\n", sorted_filename, strerror(errno));
        system("pause");
        return;
    }

    for (int i = 0; i < array_size; i++) {
        fprintf(file, "%d", array[i]);
        if (i < array_size - 1) fprintf(file, ",");
    }
    fprintf(file, "\n");

    fclose(file);
    printf("Отсортированный массив сохранен в %s\n", sorted_filename);
}

void clean_stdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}