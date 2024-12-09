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

// H�m duyet danh s�ch tu cuoi ve dau v� in ra gi� tri
void printReverse(struct Node* head) {
    if (head == NULL) {
        printf("Danh s�ch rong.\n");
        return;
    }

    // Duyet den phan tu cuoi c�ng
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Duyet nguoc tu cuoi ve dau
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->prev != NULL) {
            printf(" <-> ");
        }
        temp = temp->prev;
    }
    printf(" <-> NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n, value;

    printf("Nhap so luong phan tu trong danh s�ch: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &value);
        append(&head, value);
    }

    printf("Danh s�ch sau khi duyet nguoc:\n");
    printReverse(head);  

    // Giai ph�ng bo nho
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

