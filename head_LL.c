
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct NODE{
    int data;
    struct NODE *next;
} node;

typedef struct header{
	int mininfo;
	int maxinfo;
	int ncount;
	struct NODE *next;
}headerNode;


headerNode *deletestart(headerNode *start){
	//start next değerini tutacak bir ptr olustur
	node *ptr;
	ptr = start->next;
	
	//ptr pointer'ı silinmeden önce head node'un degerlerinde 
	//bir degisikliğe sebep olup olmadığına bakıyoruz.
	start->ncount = start->ncount - 1;
	
	if(start->maxinfo == ptr->data){
		node *temp;
		temp = start->next->next;
		
		start->maxinfo = temp->data;
		//max info güncelle
		while(temp->next != NULL){
			if(start->maxinfo < temp->data)
				start->maxinfo = temp->data;
		}
	}
	
	if(start->mininfo == ptr->data){
		node *temp;
		temp = start->next->next;
		
		start->mininfo = temp->data;
		//min info güncelle
		while(temp->next != NULL){
			if(start->mininfo < temp->data)
				start->mininfo = temp->data;
		}
	}
	
	//start'ın next degeri su anki ptr'den sonraki deger olmalıdır.
	start->next = ptr->next;
	//ptr next bağlantısını koparıp free ediyoruz.
	ptr->next = NULL;
	free(ptr);
	
	return start;
}


headerNode *insertstart(headerNode *start, int insert_this){
    //yeni bir node olustur ve degeri ata
	node *newNode;
	newNode = (node *)malloc(sizeof(node));	
	newNode->data = insert_this;
	
	//yeni node, head node'u olacağı için şu anki start node'unun next
	//değerini yeni node'un next değeri olarak ayarla
	newNode->next = start->next;
	//Start'ın next pointer'ının yeni node'u
	//göstermesini sağla
	start->next = newNode;
	
	//start node'unun değerlerini güncelle
	start->ncount = start->ncount + 1;
	
	if(start->maxinfo < insert_this)
		start->maxinfo = insert_this;
	
	if(start->mininfo > insert_this)
		start->mininfo = insert_this;

    return start;
}

headerNode *create_hll(headerNode *start){
	
	start->next = NULL;
	start->ncount = 0;
	start->maxinfo = 0;
	start->mininfo = 0;
	
	for(int i=1; i<5; i++){
		start = insertstart(start, i);
	}
	
	for(int i=-1; i>-5; i--){
		start = insertstart(start, i);
	}

    return start;
}

headerNode *traverse_hll(headerNode *start){
	node *ptr;
	int i = 0;
	//start node'unun sonraki node'unu göster
	ptr = start->next;
	
	//node'ların next değerleri null olana dek ilerle	
	while(ptr->next != NULL){
		printf("%d\t:\t%d\n", i, ptr->data);
		ptr = ptr->next;
		i = i+1;
	}
	//son node'u da yazdır
	printf("%d\t:\t%d\n", i, ptr->data);
	
	return start;

}

headerNode *giveInfo(headerNode *start){
	
	printf("\n___________________________\n");
	printf("Total Number of Node Counts : %d\n", start->ncount);
	printf("Max Value of the nodes : %d\n", start->maxinfo);
	printf("Min Value of the nodes : %d\n", start->mininfo);
	printf("First Node's Value : %d\n", start->next->data);
	printf("First Node's Address : %p\n", start->next);
	return start;
}


int main(void){
    
	headerNode hNode, *start;
	start = &hNode;
	start = create_hll(start);
	start = insertstart(start, -5555);
	
    //traversing
	start = traverse_hll(start);
	//give info
	start = giveInfo(start);
	
	start = deletestart(start);
	
	printf("\nAfter delete process!\n");
	//traversing
	start = traverse_hll(start);
	//give info
	start = giveInfo(start);

    return 0;
}
