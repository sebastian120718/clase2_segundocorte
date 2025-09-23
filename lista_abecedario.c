#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* next;
};

struct Node* createNode(char data) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    if (!n) { fprintf(stderr, "Error: memoria no reservada\n"); exit(1); }
    n->data = data;
    n->next = NULL;
    return n;
}

void insertAtEnd(struct Node** head, char data) {
    struct Node* node = createNode(data);
    if (*head == NULL) { *head = node; return; }
    struct Node* t = *head;
    while (t->next) t = t->next;
    t->next = node;
}

void printList(struct Node* head) {
    struct Node* t = head;
    while (t) {
        printf("%c -> ", t->data);
        t = t->next;
    }
    printf("NULL\n");
}

void freeList(struct Node* head) {
    struct Node* tmp;
    while (head) { tmp = head; head = head->next; free(tmp); }
}

int main() {
    struct Node* head = NULL;
    for (char c = 'a'; c <= 'z'; ++c) insertAtEnd(&head, c);

    printf("Abecedario:\n");
    printList(head);

    freeList(head);
    return 0;
}

// este codigo esta basado en el de char pero la lista es de abecedario no estrañar si le ve similitud al anterior