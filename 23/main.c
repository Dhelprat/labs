#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

// Структура узла дерева
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Создание нового узла
Node *createNode( int data ) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

// Добавление нового узла в дерево
Node *insert( Node *root, int data ) {
    if ( root == NULL ) { return createNode(data); }
    if ( data < root -> data ) { root -> left = insert(root -> left, data); }
    else { root -> right = insert(root -> right, data); }
    return root;
}

// Удаление узла из дерева
Node *deleteNode( Node *root, int data ) {
    if ( root == NULL ) { return root; }
    if ( data < root -> data ) { root -> left = deleteNode(root -> left, data); }
    else if ( data > root -> data ) { root -> right = deleteNode(root -> right, data); }
    else {
        if ( root -> left == NULL ) {
            Node *temp = root -> right;
            free(root);
            return temp;
        } else if ( root -> right == NULL ) {
            Node *temp = root -> left;
            free(root);
            return temp;
        }

        Node *temp = root -> right;
        while ( temp -> left != NULL ) { temp = temp -> left; }
        root -> data = temp -> data;
        root -> right = deleteNode(root -> right, temp -> data);
    }

    return root;
}

// Визуализации дерева
void printTree( Node *root, int n ) {
    for (int i = 0; i < n; i++) printf("   ");
    printf("%d\n", root->data);
    if (root->left !=  NULL)
        printTree(root->left, n+1);
    if (root->right !=  NULL)
        printTree(root->right, n+1);
}

// проверка на в-дерево
bool isBTree(Node* root) {
    if (root == NULL) return true;
    if (root->left == NULL && root->right == NULL) return true;
    if (root->left != NULL && root->right != NULL)
        return isBTree(root->left) && isBTree(root->right);

    return false;
}

// Освобождение памяти
void freeTree( Node *root ) {
    if ( root != NULL ) {
        freeTree(root -> left);
        freeTree(root -> right);
        free(root);
    }
}

// Это база
int main() {
    SetConsoleOutputCP(CP_UTF8);

    Node *root = NULL;
    int choice, data;
    srand(time(NULL));

    printf("Случайные значения дерева:\n");
    for ( int i = 1; i <= 10; i++ ) {
        data = rand() % 100;
        printf("%d ", data);
        root = insert(root, data);
    }

    do {
        printf("\nМеню:\n");
        printf("0 - добавить узел\n");
        printf("1 - удалить узел\n");
        printf("2 - вывести дерево\n");
        printf("3 - проверить, является ли дерево в-деревом\n");
        printf("4 - завершить работу\n");
        printf("Выберите операцию (0-4):");
        scanf("%d", &choice);

        switch ( choice ) {
            case 0:
                printf("Введите значение для добавления: ");
                scanf("%d", &data);
                root = insert(root, data);
                printf("%d - добавлен в дерево\n", data);
                break;
            case 1:
                printf("Введите значение для удаления: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                printf("%d - удалён из дерева\n", data);
                break;
            case 2:
                printf("Дерево:\n");
                printTree(root, 0);
                printf("\n");
                break;
            case 3:
                if (isBTree(root)) {
                    printf("Дерево является в-деревом\n");
                } else {
                    printf("Дерево НЕ является в-деревом\n");
                };
                break;
            case 4:
                printf("Завершение программы\n");
                break;
            default:
                printf("Неверный ввод!\n");
        }
    } while ( choice != 4 );

    freeTree(root); // Освобождаем память
    return 0;
}