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

// H�m x�a phan tu cuoi c�ng trong danh s�ch li�n ket doi
void deleteLast(struct Node** head) {
    if (*head == NULL) {
        printf("Danh s�ch rong\n");
        return;
    }
    
    struct Node* temp = *head;
    
    // Neu chi c� mot phan tu trong danh s�ch
    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }

    // Duyet den phan tu cuoi c�ng
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    // Cap nhat con tro cua phan tu truoc phan tu cuoi
    temp->prev->next = NULL;
    
    // Giai ph�ng bo nho phan tu cuoi
    free(temp);
}

// H�m duyet danh s�ch v� in ra c�c phan tu
void printList(struct Node* head) {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("Danh s�ch rong\n");
        return;
    }
    
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
    int n, value;

    printf("Nhap so luong phan tu trong danh s�ch: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &value);
        append(&head, value);
    }

    printf("Danh s�ch ban dau:\n");
    printList(head);

    // X�a phan tu cuoi c�ng
    deleteLast(&head);

    printf("Danh s�ch sau khi x�a phan tu cuoi:\n");
    printList(head);

    // Giai ph�ng bo nho
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

