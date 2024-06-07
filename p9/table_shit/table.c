#include "table.h"
#include <stdlib.h>

Table* create_table() {
    Table* table = (Table*)malloc(sizeof(Table));
    table->count = 0;
    table->capacity = 8; // Initial capacity
    table->keys = (Key*)malloc(table->capacity * sizeof(Key));
    table->values = (void**)malloc(table->capacity * sizeof(void*));
    return table;
}

void resize_table(Table* table) {
    int new_capacity = table->capacity * 2;
    table->keys = (Key*)realloc(table->keys, new_capacity * sizeof(Key));
    table->values = (void**)realloc(table->values, new_capacity * sizeof(void*));
    table->capacity = new_capacity;
}

void add_entry(Table* table, long long key_int, char key_char, void* value) {
    if (table->count == table->capacity) {
        resize_table(table);
    }
    table->keys[table->count].int_part = key_int;
    table->keys[table->count].char_part = key_char;
    table->values[table->count] = value;
    table->count++;
}

void free_table(Table* table) {
    free(table->keys);
    free(table->values);
    free(table);
}

