#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct NODE{
    struct NODE *prev;
    int data;
    struct NODE *next;
} node;

node *insertFirst2CDLL(node *head, int insert_this){
    //Bir tane Node üret, hafizada yerini aç ve verisini ata.
    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    newNode->data = insert_this; 
    
    //ptr adinda gecici bir pointer olustur ve head degerini göstersin
    node *ptr;
    ptr = head;
    //ptr'nin next degeri head'i gösterecek kadar liste üzerinde kaydir
    //böylece en son node'a ulasilmis olustur
    while(ptr->next != head){
        ptr = ptr->next;
    }
    
    //ptr'nin (artik son node) next ve newNode'un prev degerlerini düzenle
    //son node'dan sonraki node head'dir ve head'in prev ise son node'dur
    ptr->next = newNode;
    newNode->prev = ptr;
    //newNode'un head yapilacaksa next degeri eski head'dir(bu durumda 
    //su anki head) 
    //Su anki head'in prev degeri ise yeni head olacak new node yapilir
    newNode->next = head;
    head->prev = newNode;
    //artik head etiketimizi yeni node'umuza tasiyabiliriz
    head = newNode;
    
    return head;
}

node *createCDLL(node *head){
    
    head = (node *)malloc(sizeof(node));
    head->data = 0;
    head->next = head;
    head->prev = head;
    
    //Node basa ekle
    
    for(int i = 1; i<8; i++){
    	head = insertFirst2CDLL(head, i);
    }
    
    return head;
}

node *insertLast2CDLL(node *head, int insert_this){
    
    //Bir tane Node üret, hafizada yerini aç ve verisini ata.
    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    newNode->data = insert_this; 
    
    //ptr adinda gecici bir pointer olustur ve head degerini göstersin
    node *ptr;
    ptr = head;
    //ptr'nin next degeri head'i gösterecek kadar liste üzerinde kaydir
    //böylece en son node'a ulasilmis olustur
    while(ptr->next != head){
        ptr = ptr->next;
    }
    //ptr için next degeri yeni Node'u gösterecek sekilde ve yeni node'un 
    //prev degeri ptr'i gösterecek sekilde ayarlanir
    ptr->next = newNode;
    newNode->prev = ptr;
    //artik head 'in prev pointer'ini ve yeniNode'un next degerini degitirebiliriz
    head->prev = newNode;
    newNode->next = head;
    
    return head;
}

node *deleteFirst2CDLL(node *head){
    
    //ptr adinda gecici bir pointer olustur ve head degerini göstersin
    node *ptr;
    ptr = head;
    //ptr'nin next degeri head'i gösterecek kadar liste üzerinde kaydir
    //böylece en son node'a ulasilmis olustur
    while(ptr->next != head){
        ptr = ptr->next;
    }
    //head node'undan sonraki node'u ptr'dan sonraki node yaparak 
    //head node'un next node'unu head yapmak istiyoruz
    //head node silinecegi icin head'dan önceki node'un next'i headin next'i yapiyoruz
    ptr->next = head->next;
    //head'dan sonraki node'un prev degerini ise head degil ptr'i gösterecek sekilde degistiriyoruz
    head->next->prev = ptr;
    //artik head node'unun baglantilarini koparip free yapabiliriz
    head->next = NULL;
    head->prev = NULL;
    free(head);
    //yeni head node'umuz ptr'dan sonraki node olarak ayarlanabilir
    head = ptr->next;
    
    return head;
}

node *deleteLast2CDLL(node *head){
    
    //ptr adinda gecici bir pointer olustur ve head degerini göstersin
    node *ptr;
    ptr = head;
    //ptr'nin next degeri head'i gösterecek kadar liste üzerinde kaydir
    //böylece en son node'a ulasilmis olustur
    while(ptr->next != head){
        ptr = ptr->next;
    }
    //son node'daki iken prev yapilarak yeni son node'da da ulasabiliyoruz.
    //Bu yüzden ptr'nin prev pointer'inin gösterdigi node'un next degerini 
    //head node'unu gösterecek sekilde degistiriyoruz
    ptr->prev->next = head;
    //head node'umuzun prev degerini ise ptr dan onceki node'u gösterecek sekilde degistiriyoruz
    head->prev = ptr->prev;
    //artik ptr pointer'inin gösterdigi baglantialrini silerek free yapabiliriz
    ptr->next = NULL;
    ptr->prev = NULL;
    free(ptr);
    
    
    return head;
}



int main(void){
    /*
    Doubly LL ve Circular Doubly LL arasindaki fark singly LL ve Circular Singly LL arasindaki farkla aynidir.
    prev ve next pointer'larda NULL degeri olmaz.
    
    Circular LL 'de node'larda yapilan degisikliklerde iki pointer'inda da degisiklik yapilmasi gerekir.
    Avantaji ise arama operasyonunu 2 kat etkili yapabilmesidir.
    
    */
    
    node *head;
    head = createCDLL(head); //0...7 arasi elemanlari barindiran bir Circular Doubly LL olusturuldu
    head = insertFirst2CDLL(head, -222); // head node'umuz -222 oldu
    head = insertLast2CDLL(head, -5050); //son node'umuz -5050 olacak
    head = deleteFirst2CDLL(head); // -222 degerli node silinecek
    head = deleteLast2CDLL(head); //-5050 degerli node silinecek
    
    //display
    node *ptr;
    ptr = head;
    
    while(ptr->next != head){
        printf("at %p address, *next = %p, *prev= %p, data = %d\n", ptr, ptr->next, ptr->prev, ptr->data);
        ptr = ptr->next;
    }
    printf("at %p address, *next = %p, *prev= %p, data = %d\n", ptr, ptr->next, ptr->prev, ptr->data);
    
    return 0;

}
