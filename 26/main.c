#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct node {
    int value;
    struct node *next;
} node;

typedef struct stack {
    node *header;
    int len;
} stack;

void stack_push(stack *st, int val){
    node *el = malloc(sizeof(node));

    el->value = val;
    el->next = NULL;

    if ( st->header == NULL ){
        st->header = el;
    } else {
        el->next = st->header;
        st->header = el;
    }
    st->len += 1;

}

void stack_pop(stack *st){
    if ( st->len == 0 ){
        return;
    }
    node *el = st->header;
    st->header = el->next;

    free(el);
    st->len -= 1;

}

int stack_front(stack *st){
    if ( st->len != 0 ){
        return st->header->value;
    }
}

int stack_size(stack *st){
    return st->len;
}

stack* create(){
    stack *st = malloc(sizeof(stack));
    st->header = NULL;
    st->len = 0;
    return st;
}

stack* reverse(stack* st){
    stack* st1 = create();
    stack* st2 = create();

    int ln = stack_size(st);

    for ( int i = 0; i < ln; i++ ){
        stack_push(st1, stack_front(st));
        stack_push(st2, stack_front(st));
        stack_pop(st);
    }
    for ( int i = 0; i < ln; i++ ){
        stack_push(st, stack_front(st2));
        stack_pop(st2);
    }

    free(st2);
    return st1;
}

stack* merge(stack* n1, stack* n2){
    stack *st = create();
    int ln = stack_size(n1) + stack_size(n2);

    for ( int i = 0; i < ln; i++ ){
        if ( stack_size(n1) > 0 && stack_size(n2) > 0 )
            if ( stack_front(n1) > stack_front(n2) ){
                stack_push(st, stack_front(n1));
                stack_pop(n1);
            } else {
                stack_push(st, stack_front(n2));
                stack_pop(n2);
            }
        else if ( stack_size(n1) > 0 ){
            stack_push(st, stack_front(n1));
            stack_pop(n1);
        } else if ( stack_size(n2) > 0 ){
            stack_push(st, stack_front(n2));
            stack_pop(n2);
        }
    }
    return reverse(st);
}

stack* merge_sort(stack* st){
    stack* nst = reverse(reverse(st));
    if ( stack_size(nst) <= 1 ){
        return nst;
    } else {
        stack* n1 = create();
        stack* n2 = create();

        int ln = stack_size(nst);
        int d = ln / 2;

        for ( int i = 0; i < ln; i++ ){
            if ( i < d ){
                stack_push(n1, stack_front(nst));
                stack_pop(nst);
            } else {
                stack_push(n2, stack_front(nst));
                stack_pop(nst);
            }
        }

        n1 = reverse(n1);
        n2 = reverse(n2);
        return merge(merge_sort(n1), merge_sort(n2));
    }
}

void show(stack *st){
    stack* nst = reverse(st);
    int ln = stack_size(nst);

    for ( int i = 0; i < ln; i++ ){
        printf("%d ", stack_front(nst));
        stack_pop(nst);
    }
    free(nst);
}


int main() {
    SetConsoleOutputCP(CP_UTF8);

    stack* st = create();
    int choice = -1;
    int item = 0;

    printf("\nМеню:\n");
    printf("1 - добавить элемент\n");
    printf("2 - удалить элемент\n");
    printf("3 - вывести последний элемент\n");
    printf("4 - вывести стек\n");
    printf("5 - отсортировать\n");
    printf("0 - завершить работу\n");

    do {
        printf("Выберите операцию (0-5):");
        scanf("%d", &choice);

        switch ( choice ) {
            case 0:
                printf("Завершение программы\n");
                break;
            case 1:
                printf("Введите элемент для добавления:");
                scanf("%d", &item);
                stack_push(st, item);
                break;
            case 2:
                printf("Введите элемент для удаления:");
                scanf("%d", &item);
                stack_pop(st);
                break;
            case 3:
                item = stack_front(st);
                printf("Последний элемент: %d\n", item);
                break;
            case 4:
                show(st);
                printf("\n");
                break;
            case 5:
                st = merge_sort(st);
                break;
            default:
                printf("Неверный ввод!\n");
                printf("Выберите операцию (0-5):");
        }
    } while ( choice != 0 );

    return 0;
}