#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct NODE{
    struct NODE *prev;
    int val;
    struct NODE *next;
}node;


node *insertFirst2DLL(node *head, int insert_this){
	//Bir tane Node üret, hafizada yerini aç ve verisini ata.
	node *newNode;
	newNode = (node *)malloc(sizeof(node));
	newNode->val = insert_this; 
	//Bu yeni node'un next degerine o anki head'in adresini ata ve prev degerini NULL olarak ayarla
	newNode->next = head;
	newNode->prev = NULL;
	//Head node'umuzun prev pointerini yeni node'u gösterecek sekilde ayarliyoruz.
	head->prev = newNode;
	//Artik head'i olusturdugumuz yeni node olarak atiyoruz.
	head = newNode;
	
	return head;
}

node *createDLL(node *head){
	
	head = (node *)malloc(sizeof(node));
	head->val = 0;
	head->next = NULL;
	head->prev = NULL;
	
	//Node basa ekle
	for(int i = 1; i<8; i++){
		head = insertFirst2DLL(head, i);
	}

	return head;
}

node *deleteFirst2DLL(node *head){
    //ptr adinda geçici pointer olustur ve bunu head pointer'ina ata.
    node *ptr;
    ptr = head;
    //head pointer'ini kendisinin next degerine ata.
    head = head->next;
    //ptr geçici pointer'inin next degerini ve head pointer'inin prev degerini
    //NULL yap ve sonra ptr free yap.
    ptr->next = NULL;
    head->prev = NULL;
    free(ptr);

    return head;
}

node *deleteLast2DLL(node *head){
    //ptr adinda geçici pointer olustur ve bunu head pointer'ina ata.
    node *ptr;
    ptr = head;
    //ptr'nin next degeri NULL degerine sahip node'u bulunana kadar traverse et. 
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    //ptr ile önceki node arasindaki bagi koparmak icin ilk olarak önceki node'un prev 
    //pointer'inin next pointer'ini NULL yapariz. Boylece ptr prev null yaptigimizda
    //ikisi arasinda herhangi bir bag kalmayacak
    ptr->prev->next = NULL;
    ptr->prev = NULL;
    //ptr degerini free yapariz
    free(ptr);

    return head;
}

node *deleteAfter2DLL(node *head, int deleteAfterThis){
    //ptr adinda geçici pointer olustur ve bunu head pointer'ina ata.
    node *ptr;
    ptr = head;
    //ptr val degeri aranan node'un degerine esit olana kadar next yap
    while(ptr->val != deleteAfterThis && ptr->next != NULL){
        ptr = ptr->next;
    }
    //silinecek node icin gecici bir temp pointeri olusturuyoruz
    node *temp;
    temp = ptr->next;
    //ptr pointer'inin next pointeri temp yerine temp'in next pointerinin
    //point ettigi adresi göstermelidir
    ptr->next = temp->next;
    //temp node'undan sonraki node temp'i point etmek yerine ptr'i point
    //etmelidir
    temp->next->prev = ptr;
    //artik temp node'unun next ve prev pointer'larinin bagini koparabiliriz
    temp->next = NULL;
    temp->prev = NULL;
    //temp pointer'inin free yapariz
    free(temp);
    
    return head;
}

node *deleteBefore2DLL(node *head, int deleteBeforeThis){
    //ptr adinda geçici pointer olustur ve bunu head pointer'ina ata.
    node *ptr;
    ptr = head;
    //ptr val degeri aranan node'un degerine esit olana kadar next yap
    while(ptr->val != deleteBeforeThis && ptr->next != NULL){
        ptr = ptr->next;
    }
    //silinecek node icin gecici bir temp pointeri olusturuyoruz
    //temp 'in ptr prev olduguna dikkat edin
    node *temp;
    temp = ptr->prev;
    //temp node'undan önceki node temp'i point etmek yerine ptr'i point
    //etmelidir
    temp->prev->next = ptr;
    //ptr pointer'inin prev pointeri temp yerine temp'in prev pointerinin
    //point ettigi adresi göstermelidir
    ptr->prev = temp->prev;

    //artik temp node'unun next ve prev pointer'larinin bagini koparabiliriz
    temp->next = NULL;
    temp->prev = NULL;
    //temp pointer'inin free yapariz
    free(temp);


    return head;
}


int main(){
    
    node *head;
    head = createDLL(head); //0...7 arasi elemanlari barindiran bir Doubly LL olusturuldu
    head = deleteFirst2DLL(head); //7 elemanli node silinecek
    head = deleteLast2DLL(head)I //0 elemanli node silinecek
    head = deleteAfter2DLL(head, 4);//5 elemani olan node silinecek
    head = deleteBefore2DLL(head, 3);//2 elemani olan node silinecek




    return 0;
}
