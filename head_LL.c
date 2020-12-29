/*
Header LL start node'una sahiptir. 
Bu node'da deger tutulan kisimda LL'in bilgi kismi tutulurken next pointer'i ise
LL'in baslangic node'unu point eder.
Grounded header LL de son node NULL pointer'ina 
Circular header LL'de ise son node start node'una point eder.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
    int data;
    struct NODE *next;
} node;

node *insertHead(node *head, int insert_this){
    
    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    newNode->data = insert_this;
    newNode->next = NULL;

    node *ptr;
    ptr = head;

    while(ptr->next != NULL){
        ptr = ptr->next;
    }

    ptr->next = newNode;

    return head;
}

node *create_hll(node *head){
    
    int i = 0;

    node *head;
    head = (node *)malloc(sizeof(node));
    head->data = i; // number of nodes
    head->next = NULL;

    for(i= 1; i<5; i++){
        head->data = i;
        head = insertHead(head, i);    
    }

    return head;
}

node *traverse_hll(node *head){

    node *ptr;
    ptr = head->next;

    while(ptr != head){
        printf("address :%p next:%p ptr->data :%d\n");
    }


}


int main(void){
    
    //traversing


    return 0;
}
