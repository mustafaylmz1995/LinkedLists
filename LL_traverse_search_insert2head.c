#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct NODE{
	struct NODE *next;
	int data;
}node;

int main(){
	// bir *head olustur
	node *head;
	
	// bir tane head üret ve doldur
	head = (node *)malloc(sizeof(node));
	head->data = 0;
	head->next = NULL;
	
	//Bir tane Node üret, hafızada yerini aç ve verisini ata. 
	node *newNode;
	newNode = (node *)malloc(sizeof(node));
	newNode->data = 1;
	//Bu yeni node'un next değerine o anki head'in adresini ata
	newNode->next = head;
	head = newNode;
	//-----------------
	newNode = (node *)malloc(sizeof(node));
	newNode->data = 2;
	newNode->next = head;
	head = newNode;
	//-----------------
	newNode = (node *)malloc(sizeof(node));
	newNode->data = 3;
	newNode->next = head;
	head = newNode;
	//----------------
	
	//traversing
	int  i = 0;
	node *ptr;
	ptr = head;
	while(ptr->next != NULL){
		printf("%d. val = %d\n", i, ptr->data);
		ptr = ptr->next;
		i++;
	}
	
	//searching
	i=0;
	ptr = head;
	while(ptr->data != 1 && ptr->next != NULL){
		ptr = ptr->next;
		i++;
	}
	printf("%d. val = %d\n", i, ptr->data);
	
   return 0;
}
