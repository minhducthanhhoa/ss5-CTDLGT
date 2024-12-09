#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// H�m th�m mot n�t v�o cuoi danh s�ch li�n ket ��i
void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// H�m ch�n phan tu v�o danh s�ch tai vi tr� chi dinh
void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    int index = 0;

    // Neu vi tr� y�u cau ch�n v�o dau danh s�ch (vi tr� 0)
    if (position == 0) {
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
        return;
    }

    // Duyet danh s�ch de tim vi tr� ch�n
    while (temp != NULL && index < position - 1) {
        temp = temp->next;
        index++;
    }

    // Neu vi tr� kh�ng hop le
    if (temp == NULL) {
        printf("Loi vi tr� kh�ng hop le\n");
        free(newNode);
        return;
    }

    // Ch�n phan tu v�o danh s�ch tai vi tr� chi dinh
    newNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// H�m duyet danh s�ch v� in ra c�c phan tu
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" <-> ");
        }
        temp = temp->next;
    }
    printf(" <-> NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n, value, position;

    printf("Nhap so luong phan tu trong danh s�ch: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &value);
        append(&head, value);
    }

    printf("Danh s�ch ban dau:\n");
    printList(head);

    // Nhap gi� tri v� vi tr� can ch�n
    printf("Gi� tri can ch�n: ");
    scanf("%d", &value);
    printf("Vi tr� can ch�n: ");
    scanf("%d", &position);

    // Ch�n phan tu v�o danh s�ch tai vi tr� chi dinh
    insertAtPosition(&head, value, position);

    printf("Danh s�ch sau khi ch�n:\n");
    printList(head);

    // Giai ph�ng b?o nho
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

