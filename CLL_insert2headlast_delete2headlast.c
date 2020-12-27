#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct NODE{
	struct NODE *next;
	int data;
}node;

node *createCLL(node *head){
	// bir tane head üret ve doldur
	head = (node *)malloc(sizeof(node));
	head->data = 0;
	head->next = NULL;
	//bir adet geçici ptr üret ve head'e eşitle
	node *ptr;
	ptr = head;
	
	//Bir tane Node üret, hafızada yerini aç ve verisini ata. 
	//Bu yeni node'un next değerine o anki head'in adresini ata
	//Artık head'i oluşturduğumuz yeni node olarak atıyoruz.
	node *newNode;
	for(int i =1; i<5; i++){
		newNode = (node *)malloc(sizeof(node));
		newNode->data = i;
		newNode->next = head;
		head = newNode;
	}
	
	//ilk nodu tutan ptr'nin next pointerını en son oluşturulan ve
	//head olarak isimlendirilen noda işaret edecek şekilde ata
	ptr->next = head;
	
	return head;
}

node *insertHead2CLL(node *head){
	
	//Bir tane Node üret, hafızada yerini aç ve verisini ata.
	node *newNode;
	newNode = (node *)malloc(sizeof(node));
	newNode->data = 9999;
	newNode->next = NULL;
	//ptr adında geçici pointer oluştur ve bunu head pointer'ına ata. 
	node *ptr;
	ptr = head;
	//ptr ile son node (next değeri head'e point eden node) kadar traverse et.
	while(ptr->next != head){
		ptr = ptr->next;
	}
	//ptr'nin next değerini yeni oluşturulan node'a işaret edecek şekilde değiştir.
	ptr->next = newNode;
	//Yeni node'un next değerini head'e point edecek şekilde değiştir.
	newNode->next = head;
	//Artık head'i oluşturduğumuz yeni node olarak atıyoruz.
	head = newNode;
	
	return head;
}

node *insertLast2CLL(node *head){
	//Dairesel LL'in başına bir node ekleyecek gibi adımları uygularız. 
	//Tek fark ise head pointerın yerini yeni eklediğimiz node olarak değiştirmeyiz.
	
	//Bir tane Node üret, hafızada yerini aç ve verisini ata.
	node *newNode;
	newNode = (node *)malloc(sizeof(node));
	newNode->data = 5050;
	newNode->next = NULL;
	//ptr adında geçici pointer oluştur ve bunu head pointer'ına ata. 
	node *ptr;
	ptr = head;
	//ptr ile son node (next değeri head'e point eden node) kadar traverse et.
	while(ptr->next != head){
		ptr = ptr->next;
	}
	//ptr'nin next değerini yeni oluşturulan node'a işaret edecek şekilde değiştir.
	ptr->next = newNode;
	//Yeni node'un next değerini head'e point edecek şekilde değiştir.
	newNode->next = head;
	
	return head;
}

node *deleteHead2CLL(node *head){
	//ptr adında geçici pointer oluştur ve bunu head pointer'ına ata. 
	node *ptr;
	ptr = head;
	//ptr ile son node (next değeri head'e point eden node) kadar traverse et.
	while(ptr->next != head){
		ptr = ptr->next;
	}
	//ptr geçici pointer'ının next değerini head pointer'ının next değeri yap ve 
	//sonra head pointer'ının gösterdiği değeri free yap.
	ptr->next = head->next;
	free(head);
	//head pointer'ını ptr'nin next değerine eşitle.
	head = ptr->next;
	
	return head;
}

node *deleteLast2CLL(node *head){
	//ptr adında geçici pointer oluştur ve bunu head pointer'ına ata. 
	node *ptr;
	ptr = head;
	//preptr adında oluşturduğun ikinci bir geçici pointer oluştur ve bunu da ptr pointer'ına atayarak ilklendir.
	node *preptr;
	preptr = ptr;
	//ptr'nin next değeri ile head node'unu gösterene kadar traverse et. Bu sırada preptr değerini, 
	//ptr değeri next olmadan hemen önceki ptr değerine ata. preptr her zaman ptr pointer'ının 
	//gösterdiği node'un bir öncesini gösterir.
	while(ptr->next != head){
		preptr = ptr;
		ptr = ptr->next;
	}
	//preptr pointer'ının next değerini head nodunun adresini gösterecek şekilde değiştir.
	preptr->next = head;
	//ptr geçici pointer'ının next değerini NULL yap ve sonra ptr pointer'ının gösterdiği değeri free yap.
	ptr->next = NULL;
	free(ptr);
	
	return head;
}

int main(){
	node *head;
	head = createCLL(head); // 0..4 kadar nodelar bulunan Circular LL
	
	head = insertHead2CLL(head); // 9999 nodunu başa ekle
	
	head = insertLast2CLL(head); // 5050 nodunu sona ekle

	head = deleteHead2CLL(head); // bastaki 9999 degerli node u silecek
	
	head = deleteLast2CLL(head); //sondaki 5050 nodu silinecek
	
   return 0;
}
