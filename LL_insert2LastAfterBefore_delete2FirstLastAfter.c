#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct NODE{
	struct NODE *next;
	int data;
}node;

node *createLL(node *head){
	// bir tane head üret ve doldur
	head = (node *)malloc(sizeof(node));
	head->data = 0;
	head->next = NULL;

	//Bir tane Node üret, hafızada yerini aç ve verisini ata. 
	//Bu yeni node'un next değerine o anki head'in adresini ata
	//Artık head'i oluşturduğumuz yeni node olarak atıyoruz.
	node *newNode;
	for(int i = 1; i<5; i++){
		newNode = (node *)malloc(sizeof(node));
		newNode->data = i;
		newNode->next = head;
		head = newNode;
	}
	
	return head;
}

node *insertLast(node *head){
	//sonuna bir node ekleme	
	//Bir tane Node üret, hafızada yerini aç ve verisini ata. 
	node *newNode;
	newNode = (node *)malloc(sizeof(node));
	newNode->data = -2222;
	//Bu yeni node'un next değerine NULL ata.
	newNode->next = NULL;
	//ptr adında geçici pointer oluştur ve bunu head pointer'ına ata.
	node *ptr; //temporary
	ptr = head;
	//ptr ile son node (next değeri NULL olan) kadar traverse et.
	while(ptr->next != NULL){
		ptr= ptr->next;
	}
	//Artık ptr'nin next değerini yeni node'umuzu gösterecek şekilde değiştirebiliriz.
	ptr->next =newNode;
	
	return head;
}

node *insertAfter(node *head){
	//Bir tane Node üret, hafızada yerini aç ve verisini ata.
	node *newNode;
	newNode = (node *)malloc(sizeof(node));
	newNode->data = 9999;
	//ptr adında geçici pointer oluştur ve bunu head pointer'ına ata.
	node *ptr; //temporary
	ptr = head;
	//preptr adında ikinci bir geçici pointer oluştur ve bunu da ptr pointer'ına atayarak ilklendir.
	node *preptr;
	preptr = ptr;
	//preptr ile aranan değere sahip node bulunana kadar traverse et. 
	//Bu sırada preptr değerini, ptr değeri next olmadan hemen önceki ptr değerine ata. 
	//preptr her zaman ptr pointer'ının gösterdiği node'un bir öncesini gösterir.
	while(preptr->data != 3){
		preptr = ptr; 
		ptr = ptr->next;
	}
	//Belirtilen node preptr tarafından bulunduğunda preptr'nin next değeri 
	//yeni oluşturulan node'u gösterecek şekilde değiştirilirken; 
	//yeni oluşturulan node'un next değeri 
	//ptr pointer'ının gösterdiği node'u gösterecek şekilde değiştirilir.
	preptr->next = newNode;
	newNode->next = ptr;
	
	return head;
}

node *insertBefore(node *head){
	
	//Bir tane Node üret, hafızada yerini aç ve verisini ata.
	node *newNode;
	newNode = (node *)malloc(sizeof(node));
	newNode->data = 8888;
	//ptr adında geçici pointer oluştur ve bunu head pointer'ına ata.
	node *ptr; //temporary
	ptr = head;
	//preptr adında ikinci bir geçici pointer oluştur ve bunu da ptr pointer'ına atayarak ilklendir.
	node *preptr;
	preptr = ptr;
	//ptr ile aranan değere sahip node bulunana kadar traverse et. 
	//Bu sırada preptr değerini, ptr değeri next olmadan hemen önceki ptr değerine ata. 
	//preptr her zaman ptr pointer'ının gösterdiği node'un bir öncesini gösterir.
	while(ptr->data != 1 && ptr->next != NULL){
		preptr = ptr; 
		ptr = ptr->next;
	}
	//Belirtilen node ptr tarafından bulunduğunda preptr'nin next değeri 
	//yeni oluşturulan node'u gösterecek şekilde değiştirilirken; 
	//yeni oluşturulan node'un next değeri 
	//ptr pointer'ının gösterdiği node'u gösterecek şekilde değiştirilir.
	preptr->next = newNode;
	newNode->next = ptr;
	
	return head;
}

node *deleteFirst(node *head){
	//ptr adında geçici pointer oluştur ve bunu head pointer'ına ata. 
	node *ptr;
	ptr = head;
	//head pointer'ını kendisinin next değerine ata.
	head = head->next;
	//ptr geçici pointer'ının next değerini NULL yap ve sonra kendisini free yap.
	ptr->next = NULL;
	free(ptr);
	
	return head;
}

node *deleteLast(node *head){
	
	//ptr adında geçici pointer oluştur ve bunu head pointer'ına ata. 
	node *ptr;
	ptr = head;
	//preptr adında oluşturduğun ikinci bir geçici pointer oluştur ve 
	//bunu da ptr pointer'ına atayarak ilklendir.
	node *preptr;
	preptr = ptr;
	//ptr ile NULL değerine sahip node bulunana kadar traverse et. 
	//Bu sırada preptr değerini, ptr değeri next olmadan hemen önceki ptr değerine ata. 
	//preptr her zaman ptr pointer'ının gösterdiği node'un bir öncesini gösterir.
	while(ptr->next != NULL){
		preptr = ptr;
		ptr = ptr->next;
	}
	//preptr pointer'ının next değerini NULL yap.
	preptr->next =NULL;
	//ptr geçici pointer'ını free yap.
	free(ptr);
	
	return head;
}

node *deleteAfter(node *head){
	
	//ptr adında geçici pointer oluştur ve bunu head pointer'ına ata.
	node *ptr;
	ptr = head;
	//preptr adında oluşturduğun ikinci bir geçici pointer oluştur ve 
	//bunu da ptr pointer'ına atayarak ilklendir.
	node *preptr;
	preptr = ptr;
	//preptr ile belirtilen değerine sahip node'u bulana kadar traverse et. 
	//Bu sırada preptr değerini, ptr değeri next olmadan hemen önceki ptr değerine ata. 
	//preptr her zaman ptr pointer'ının gösterdiği node'un bir öncesini gösterir.
	while(preptr->data != 9999 && ptr->next!=NULL){
		preptr = ptr;
		ptr = ptr->next;
	}
	//Belirtilen node preptr tarafından bulunduğunda preptr'nin next değeri 
	//ptr'nin next değerini gösterecek şekilde değiştirilir, daha sonra ptr'nin next değeri 
	//NULL yapılır ve en sonunda ptr geçici pointer'ını free yapılır.
	preptr->next = ptr->next;
	ptr->next = NULL;
	free(ptr);
	
	return head;
}

int main(){
	// bir *head olustur
	node *head;
	head = createLL(head); //0..4 bir LL olusturulacak
	//sonuna bir node ekleme
	head = insertLast(head); // en sona -2222 eklenecek
	//node dan sonraya ekleme
	head = insertAfter(head); //3 ten sonra 9999 eklenecek
	//node dan önceye ekleme
	head = insertBefore(head); //1 ten önceye 8888 eklenecek
	//bastaki node silinecek
	head = deleteFirst(head);
	//sondaki node silinecek
	head = deleteLast(head);
	//node dan sonraki node silinecek
	head = deleteAfter(head);//9999 dan sonraki node silinecek
	
	
	free(head);
   return 0;
}


