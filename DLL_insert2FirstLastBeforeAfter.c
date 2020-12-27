#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct NODE{
	struct NODE *prev;
	int val;
	struct NODE *next;
}node;


node *insertFirst2DLL(node *head, int insert_this){
	//Bir tane Node üret, hafızada yerini aç ve verisini ata.
	node *newNode;
	newNode = (node *)malloc(sizeof(node));
	newNode->val = insert_this; 
	//Bu yeni node'un next değerine o anki head'in adresini ata ve prev değerini NULL olarak ayarla
	newNode->next = head;
	newNode->prev = NULL;
	//Head node'umuzun prev pointerını yeni node'u gösterecek şekilde ayarlıyoruz.
	head->prev = newNode;
	//Artık head'i oluşturduğumuz yeni node olarak atıyoruz.
	head = newNode;
	
	return head;
}

node *createDLL(node *head){
	
	head = (node *)malloc(sizeof(node));
	head->val = 0;
	head->next = NULL;
	head->prev = NULL;
	
	//Node basa ekle
	for(int i = 1; i<5; i++){
		head = insertFirst2DLL(head, i);
	}

	return head;
}

node *insertLast2DLL(node *head, int insert_this){
	//Bir tane Node üret, hafızada yerini aç ve verisini ata. 
	node *newNode;
	newNode = (node *)malloc(sizeof(node));
	newNode->val = insert_this; 
	//Bu yeni node'un next değerine NULL ata.
	newNode->next = NULL;
	//ptr adında geçici pointer oluştur ve bunu head pointer'ına ata.
	node *ptr;
	ptr = head;
	//ptr ile son node (next değeri NULL olan) kadar traverse et.
	while(ptr->next != NULL){
		ptr = ptr->next;
	}
	//Artık ptr'nin next değerini yeni node'umuzu gösterecek şekilde değiştiririz.
	ptr->next = newNode;
	//Yeni node'umuzun prev değerini ise ptr gösterecek şekilde değiştiririz.
	newNode->prev = ptr;
	
	return head;
}

node *insertAfter2DLL(node *head, int after_this, int insert_this){

	//Bir tane Node üret, hafızada yerini aç ve verisini ata. 
	node *newNode;
	newNode = (node *)malloc(sizeof(node));
	newNode->val = insert_this;
	//ptr adında geçici pointer oluştur ve bunu head pointer'ına ata. 
	node *ptr;
	ptr = head;
	//ptr ile aranan değere sahip node bulunana kadar traverse et. (Devamındaki sıra önemlidir!)
	while(ptr->val != after_this && ptr->next != NULL){
		ptr = ptr->next;
	}
	//Yeni Node'un next pointer'ı ptr'ın next pointer'ına eşitlenir.
	newNode->next = ptr->next;
	//Yeni Node'un prev pointer'ın ptr'a eşitlenir.
	newNode->prev = ptr;
	//ptr'ın next pointer'ındaki node'un prev pointer'ı yeni Node'a eşitlenir.
	ptr->next->prev = newNode;
	//ptr'ın next pointer'ı ise yeni Node'a eşitlenir.
	ptr->next = newNode;
	
	return head;
}

node *insertBefore2DLL(node *head, int before_this, int insert_this){
	
	//Bir tane Node üret, hafızada yerini aç ve verisini ata. 
	node *newNode;
	newNode = (node *)malloc(sizeof(node));
	newNode->val = insert_this;
	//ptr adında geçici pointer oluştur ve bunu head pointer'ına ata.
	node *ptr;
	ptr = head;
	//ptr ile aranan değere sahip node bulunana kadar traverse et. (Devamındaki sıra önemlidir!)
	while(ptr->val != before_this && ptr->next != NULL){
		ptr = ptr->next;
	}
	//ptr'ın prev pointer'ındaki node'un next pointer'ı yeni Node'a eşitlenir.
	ptr->prev->next = newNode;
	//Yeni Node'un prev pointer'ı ptr'nın prev pointerına eşitlenir.
	newNode->prev = ptr->prev;
	//Yeni Node'un next pointer'ı ptr eşitlenir.
	newNode->next = ptr;
	//ptr'ın prev pointer'ı ise yeni Node'a eşitlenir.
	ptr->prev = newNode;
	
	return head;
}

int main(void){
	node *head;
	
	head = createDLL(head); //0..4 kadat doubly LL olusturulacak
	head = insertFirst2DLL(head, 9999); //en basa eklenecek node 9999 degerli
	head = insertLast2DLL(head, -120);//-120 en son node olarak eklenecek

	head = insertAfter2DLL(head,3, -5050);//3 den sonra -5050 ekleyecek
	
	head = insertBefore2DLL(head, 2, -2222);//2 den önce -2222 ekleyecek
	
	return 0;
}
