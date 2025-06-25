#include "common.h"
#include "menu.h"
#include "func.h"

int main() {
    setlocale(LC_ALL, "Rus");
    reset_sorted_file();
    system_sort();
    return 0;
}