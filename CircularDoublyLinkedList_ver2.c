#include <stdio.h>
#include <stdlib.h> //malloc, calloc, realloc free


typedef struct Node {
	struct Node* next;
	struct Node* prev;
	int data;
} node;


typedef struct CircularDoublyLinkedList {
	node* head;
	node* tail;
	int nofElement;

}CDLL;


node *createnode(void) {
	node *newNode = (node*)malloc(sizeof(node));
	if (newNode == NULL) {
		return NULL;
	}
	else {
		newNode->next = NULL;
		newNode->prev = NULL;
		newNode->data = 0;
		return newNode;
	}
	
}
void startCircularDoublyLinkedList(CDLL *newCDLL) {
	node* head = createnode();
	node* tail = createnode();
	
	node* newNode = createnode();
	head = newNode;
	tail = newNode;


	newCDLL->head = head;
	newCDLL->tail = tail;

	newCDLL->head->next = tail;
	newCDLL->tail->prev = head;

	newCDLL->head->prev = tail;
	newCDLL->tail->next = head;

	newCDLL->nofElement = 1;


	return newCDLL;

}

node* insert2CDLL(CDLL* newCDLL, int insert_this) {
	node* dumyNode = createnode();
	if (dumyNode == NULL) {
		return NULL;
	}
	dumyNode->data = insert_this;
	dumyNode->next = newCDLL->head;
	dumyNode->prev = newCDLL->tail;

	newCDLL->head->prev = dumyNode;
	newCDLL->tail->next = dumyNode;
	newCDLL->nofElement++;

	return dumyNode;
}


void insertFirst2CDLL(CDLL *newCDLL, int insert_this) {
	newCDLL->head = insert2CDLL(newCDLL, insert_this);
}


void insertLast2CDLL(CDLL *newCDLL, int insert_this) {
	newCDLL->tail = insert2CDLL(newCDLL, insert_this);
}



void deleteFirst2CDLL(CDLL* newCDLL) {
	if (newCDLL->nofElement == 0) {
		printf("UNDERFLOW!!!\n");
		return;
	}
	else if (newCDLL->nofElement == 1) {
		printf("Head node can not be deleted!\n");
		return;
	}
	else {
		node* dumyNode = newCDLL->head;

		newCDLL->tail->next = newCDLL->head->next;
		newCDLL->head->next->prev = newCDLL->tail;

		newCDLL->head = newCDLL->head->next;
		newCDLL->nofElement--;

		dumyNode->next = NULL;
		dumyNode->prev = NULL;
		free(dumyNode);
	}

	if (newCDLL->nofElement == 1) {
		newCDLL->head->next = NULL;
		newCDLL->tail->next = NULL;
	}

}

void deleteLast2CDLL(CDLL* newCDLL) {
	if (newCDLL->nofElement == 0) {
		printf("UNDERFLOW!!!\n");
		return;
	}
	else if (newCDLL->nofElement == 1) {
		printf("Head node can not be deleted!\n");
		return;
	}
	else {
		node* dumyNode = newCDLL->tail;

		newCDLL->head->prev = newCDLL->tail->prev;
		newCDLL->tail->prev->next = newCDLL->head;

		newCDLL->tail = newCDLL->tail->prev;
		newCDLL->nofElement--;

		dumyNode->next = NULL;
		dumyNode->prev = NULL;
		free(dumyNode);
	}

	if (newCDLL->nofElement == 1) {
		newCDLL->head->next = NULL;
		newCDLL->tail->next = NULL;
	}
}




void display(CDLL* newCDLL) {
	int i = newCDLL->nofElement;
	node* newDumy = newCDLL->head;


	for (; i > 0; i--) {
		printf("%p\t%d\n", newDumy, newDumy->data);
		newDumy = newDumy->next;
	}
	printf("\n");
}


int main(void) {

	CDLL CDLinkedList;

	startCircularDoublyLinkedList(&CDLinkedList);
	display(&CDLinkedList);

	insertFirst2CDLL(&CDLinkedList, 1);
	display(&CDLinkedList);

	insertLast2CDLL(&CDLinkedList, 1);
	display(&CDLinkedList);

	deleteFirst2CDLL(&CDLinkedList);
	display(&CDLinkedList);

	deleteFirst2CDLL(&CDLinkedList);
	display(&CDLinkedList);

	deleteFirst2CDLL(&CDLinkedList);
	display(&CDLinkedList);

	deleteFirst2CDLL(&CDLinkedList);
	insertFirst2CDLL(&CDLinkedList, 3);
	display(&CDLinkedList);

	deleteLast2CDLL(&CDLinkedList);
	display(&CDLinkedList);

	return 0;
}
