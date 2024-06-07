#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define MENU_ITEMS 6

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int countNodes(Node* head) {
    if (head == NULL) {
        return 0;
    }

    Node* current = head;
    int count = 0;
    do {
        count++;
        current = current->next;
    } while (current != head);

    return count;
}

void appendNode(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode;
        return;
    }

    Node* current = *head;
    while (current->next != *head) {
        current = current->next;
    }

    current->next = newNode;
    newNode->next = *head;
}

void insertNode(Node** head, int data, int index) {
    if (index < 0) {
        return;
    } else if (index >= countNodes(*head) ) {
        appendNode(head, data);
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode;
        return;
    }

    Node* current = *head;
    int count = 0;
    while (count < index % countNodes(*head) - 1) {
        current = current->next;
        count++;
    }

    if (index == 0) {
        Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        newNode->next = *head;
        last->next = newNode;
        *head = newNode;
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void handleInsert(Node** lst) {
    int index; char holder; int value;

    printf("Введите индекс: ");
    if (scanf("%d", &index) != 1) {
        return;
    }

    printf("Введите значение для добавления: ");
    scanf("%c", &holder);
    if (scanf("%d", &value) != 1) {
        return;
    }

    insertNode(lst, value, index);
    printf("Значение успешно добавлено!\n");
}

void handleAppend(Node** lst) {
    char holder; int value;

    printf("Введите значение для добавления: ");
    scanf("%c", &holder);
    if (scanf("%d", &value) != 1) {
        return;
    }

    appendNode(lst, value);
    printf("Значение успешно добавлено!\n");
}


void clearListWithValue(Node** head, int value) {
    Node* current = *head;
    int valueFound = 0;

    if (*head == NULL) {
        return;
    }

    do {
        if (current->data == value) {
            valueFound = 1;
            break;
        }
        current = current->next;
    } while (current != *head);

    if (valueFound) {
        current = *head;
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
            if (current == *head) {
                break;
            }
        }
        *head = NULL;
    }
}

void handleItem(Node** lst) {
    char holder;
    int value;

    printf("Введите значение для проверки: ");
    scanf("%c", &holder);
    if (scanf("%d", &value) != 1) {
        return;
    }
    clearListWithValue(lst, value);
}

void printList(Node* head) {
    if (head == NULL) {
        printf("Список пуст\n");
        return;
    }
    Node* current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

void deleteNode(Node** head, int index) {
    if (*head == NULL) {
        return;
    }

    Node* current = *head;
    Node* prev = NULL;
    int count = 0;

    if (index == 0) {
        Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        last->next = (*head)->next;
        free(*head);
        *head = last->next;
        return;
    }

    while (count < index % countNodes(*head)) {
        prev = current;
        current = current->next;
        count++;
    }

    prev->next = current->next;
    free(current);
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    Node* head = NULL;
    int choice; int ind;

    printf("\nМеню:\n");
    printf("1 - добавить элемент\n");
    printf("2 - вывести список\n");
    printf("3 - вывести длину списка\n");
    printf("4 - выбрать элемент\n");
    printf("5 - удалить элемент\n");
    printf("0 - завершить работу\n");

    do {
        printf("Выберите операцию (0-4):");
        scanf("%d", &choice);

        switch ( choice ) {
        case 0:
            printf("Завершение программы\n");
            break;
        case 1:
            handleInsert(&head);
            break;
        case 2:
            printList(*&head);
            break;
        case 3:
            printf("Длина списка: %d", countNodes(*&head));
            printf("\n");
            break;
        case 4:
            handleItem(&head);
            break;
        case 5:
            printf("Введите индекс элемента для удаления: ");
            scanf("%d", &ind);
            deleteNode(&head, ind);
            break;

        default:
            printf("Неверный ввод!\n");
        }
    } while ( choice != 0 );

    return 0;
}