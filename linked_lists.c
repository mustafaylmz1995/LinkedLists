#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *start = NULL;

struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *sort_list(struct node *);
struct node *clear_list(struct node *);

struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);

struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_node(struct node *);
struct node *delete_after(struct node *);




int main(int argc, char *argv[]){

    int option;
    do{
        printf("\n\n*************MAIN MENU*************\n");
        printf(" 1: Create a list\n");
        printf(" 2: Display the list\n");
        printf(" 3: Sort the list\n");
        printf(" 4: Clear the list\n");
        printf(" 5: Add a node at the beginning\n");
        printf(" 6: Add a node at the end\n");
        printf(" 7: Add a node before a given node\n");
        printf(" 8: Add a node after a given node\n");
        printf(" 9: Delete the node at the beginning\n");
        printf(" 10: Delete the node at the end\n");
        printf(" 11: Delete a given node\n");
        printf(" 12: Delete a node after a given node\n");
        printf(" 13: EXIT!\n");

        printf("\n Enter your option :\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1: //Create a list
            start = create_ll(start);
            printf("\nA LINKED LIST CREATED!\n");
            break;
        case 2: //Display the list
            start = display(start);
            break;
        case 3: //Sort the list
            start = sort_list(start);
            break;
        case 4: //Clear the list
            start = clear_list(start);
            printf("\nLINKED LIST DELETED\n");
            break;
        case 5: //Add a node at the beginning
            start = insert_beg(start);
            break;
        case 6: //Add a node at the end
            start= insert_end(start);
            break;
        case 7: //Add a node before a given node
            start = insert_before(start);
            break;
        case 8: //Add a node after a given node
            start = insert_after(start);
            break;
        case 9: //Delete the node at the beginning
            start = delete_beg(start);
            break;
        case 10: //Delete the node at the end
            start = delete_end(start);
            break;
        case 11: //Delete a given node
            start = delete_node(start);
            break;
        case 12: //Delete a node after a given node
            start = delete_after(start);
            break;
        default:
            break;
        }

    }while(option != 13);

    getchar();

    return 0;
}

struct node *create_ll(struct node *start){

    struct node *new_node, *ptr;
    int num;
    
    printf("\nEnter -1 to end\n");
    printf("Enter the data: \n");
    scanf("%d", &num);

    while(num != -1){

        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;

        if(start == NULL){

            new_node->next = NULL;
            start = new_node;
        }else{

            ptr = start;

            while(ptr->next != NULL){
                ptr=ptr->next;
            }
            ptr->next = new_node;
            new_node->next=NULL;
        }

        printf("\nEnter -1 to end\n");
        printf("Enter the data: \n");
        scanf("%d", &num);
    }

    return start;
}
struct node *display(struct node *start){

    struct node *ptr = start;

    while(ptr != NULL){
        printf("\n\t %d", ptr->data);
        ptr = ptr->next;
    }

    return start;
}
struct node *sort_list(struct node *start){
    struct node *ptr1, *ptr2;
    int temp;
    ptr1 = start;

    while(ptr1->next != NULL){
        
        ptr2 = ptr1->next;
        while(ptr2 != NULL){
            if(ptr1->data > ptr2->data){
                temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    

    return start;
}
struct node *clear_list(struct node *start){

    struct node *ptr;
    if(start != NULL){
        ptr=start;

        while(ptr!=NULL){
            printf("\n %d is to be deleted next", ptr->data);
            start = delete_beg(ptr);
            ptr = start;
        }
    }

    return start;
}

struct node *insert_beg(struct node *start){
    struct node *new_node;
    int num;
    
    printf("\nEnter the data: \n");
    scanf("%d", &num);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = start;
    start = new_node;
    
    return start;
}
struct node *insert_end(struct node *start){
    struct node *ptr, *new_node;
    int num;
    
    printf("\nEnter the data: \n");
    scanf("%d", &num);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = NULL;

    ptr = start;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = new_node;

    return start;
}
struct node *insert_before(struct node *start){
    struct node *new_node, *ptr, *pre_ptr;
    int num, val;

    printf("\nEnter the data : \n");
    scanf("%d", &num);

    printf("\nEnter the value before which the data has to be inserted : \n");
    scanf("%d", &val);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = NULL;

    ptr = start;
    if(ptr->data == val){
        new_node->next = ptr;
        start = new_node;
    }else{
        while(ptr->data != val){
            pre_ptr = ptr;
            ptr = ptr->next;
        }
        pre_ptr->next = new_node;
        new_node->next = ptr;
    }
    

    return start;
}
struct node *insert_after(struct node *start){
    struct node *new_node, *ptr, *pre_ptr;
    int num, val;

    printf("\nEnter the data : \n");
    scanf("%d", &num);

    printf("\nEnter the value before which the data has to be inserted : \n");
    scanf("%d", &val);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;

    ptr = start;
    pre_ptr = ptr;
    while(pre_ptr->data != val){
        pre_ptr = ptr;
        ptr = ptr->next;
    }
    pre_ptr->next=new_node;
    new_node->next = ptr;

    return start;
}

struct node *delete_beg(struct node *start){
    struct node *ptr;
    ptr = start;
    start = start->next;
    free(ptr);
    return start;
}
struct node *delete_end(struct node *start){
    struct node *ptr, *pre_ptr;
    
    ptr = start;
    while(ptr->next != NULL){
        pre_ptr = ptr;
        ptr = ptr->next;
    }
    pre_ptr->next = NULL;
    free(ptr);

    return start;
}
struct node *delete_node(struct node *start){
    struct node *ptr, *pre_ptr;
    int val;

    printf("\nEnter the value before which the data has to be deleted : \n");
    scanf("%d", &val);

    ptr = start;
    if(ptr->data == val){
        start = delete_beg(start);
    }else{
        while(ptr->data != val){
            pre_ptr = ptr;
            ptr = ptr->next;
        }
        pre_ptr->next = ptr->next;
        free(ptr);
    }

    return start;
}
struct node *delete_after(struct node *start){
    struct node *ptr, *pre_ptr;
    int val;

    printf("\nEnter the value before which the data has to be deleted : \n");
    scanf("%d", &val);

    ptr = start;
    pre_ptr = ptr;

    while(pre_ptr->data != val){
        pre_ptr = ptr;
        ptr = ptr->next;
    }
    pre_ptr->next = ptr->next;
    free(ptr);

    return start;

}

