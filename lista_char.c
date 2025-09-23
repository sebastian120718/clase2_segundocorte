
//listas enlazadas
#include <stdio.h>
#include <stdlib.h>

struct Node{
    char data; // 4 bytres
    struct Node* next;

    
};

struct Node* createNode(char data){
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
        printf("%c -> ",temp ->data);
        temp=temp ->next;
    
    }
    printf("NULL\n");

};

int main(){
    struct Node* head= createNode('a');   
    struct Node* first= createNode('b');   
    struct Node* second= createNode('c');   
    struct Node* third= createNode('d');
    
    
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

//no olvidar compilar para dar prueba que funciona el codigo