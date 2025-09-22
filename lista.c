#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data; // 4 bytres
    struct Node* next;

    
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL){
        printf("error: memoria no reservada");

    }
    
    newNode ->data = data;
    newNode ->next = NULL;
    return newNode;
};    

void printList(struct Node* head){
    struct Node* temp = head;
    while (temp !=NULL){
        printf("%d -> ",temp ->data);
        temp=temp ->next;
    
    }
    printf("NULL\n");

};

int main(){
    struct Node* head= createNode(10);   
    struct Node* first= createNode(11);   
    struct Node* second= createNode(12);   
    struct Node* third= createNode(13);
    
    
    head ->next = first;;
    first -> next = second;
    second -> next = third;

    printList(head);

    free(head);
    free(first);
    free(second);
    free(third);

    return 0;

};

