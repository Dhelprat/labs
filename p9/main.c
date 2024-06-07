#include <stdio.h>
#include <stdlib.h>
#include "key_functions/keys.h"
#include "lab_staff/utils.h"
#include "table_shit/table.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);

    Table* table = create_table();

    random_assignment(table);
    display_table(table);

    int choice;
    while (1) {
        printf("Выберите действие:\n");
        printf("1. Сортировать таблицу\n");
        printf("2. Найти ключ\n");
        printf("3. Отобразить таблицу\n");
        printf("4. Завершить работу\n");
        printf("Введите свой выбор (1-4): ");
        if (scanf("%d", &choice) != 1) {
            printf("Неверный ввод \n");
            fflush(stdin);
            continue;
        }

        if (choice == 4) {
            break;
        }

        switch (choice) {
        case 1:
            linear_selection_sort(table);
            printf("Таблица успешно отсортирована.\n\n");
            break;
        case 2: {
                long long key_int;
                char key_char;
                printf("Введите ключ поиска: ");
                if (scanf("%lld %c", &key_int, &key_char) != 2) {
                    printf("Неверный ввод\n\n");
                    break;
                }
                void* value = binary_search(table, key_int, key_char);
                if (value != NULL) {
                    printf("Значение найдено: %s\n\n", (char*)value);
                } else {
                    printf("Указанный ключ не был найден в таблице\n\n");
                }
                break;
        }
        case 3:
            display_table(table);
            break;
        default:
            printf("Неверный ввод\n\n");
        }
    }

    free_table(table);
    return 0;
}
