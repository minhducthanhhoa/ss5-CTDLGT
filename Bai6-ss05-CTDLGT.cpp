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

void printList(struct Node* head) {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("Danh sách rong\n");
        return;
    }
    
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" <-> ");
        }
        temp = temp->next;
    }
    printf("\n");
}

void replaceValue(struct Node* head, int oldValue, int newValue) {
    struct Node* temp = head;
    int found = 0;

    while (temp != NULL) {
        if (temp->data == oldValue) {
            temp->data = newValue; 
            found = 1;
        }
        temp = temp->next;
    }

    if (!found) {
        printf("Không tim thay phan tu có giá tri can thay the\n");
    }
}

int main() {
    struct Node* head = NULL;
    int n, value, oldValue, newValue;

    printf("Nhap so luong phan tu trong danh sách: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &value);
        append(&head, value);
    }

    printf("Danh sách ban dau:\n");
    printList(head);

    printf("Nhap giá tri can thay th?: ");
    scanf("%d", &oldValue);
    printf("Nhap giá tri moi: ");
    scanf("%d", &newValue);

    replaceValue(head, oldValue, newValue);

    printf("Danh sách sau khi thay the:\n");
    printList(head);

    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

