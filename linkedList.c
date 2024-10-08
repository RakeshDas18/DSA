#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* head = NULL;

void insertNode(int n){
    int i, data;
    struct node *newNode, *temp;
    head = NULL;
    for(i=1;i<=n;i++){
        newNode = (struct node*)malloc(sizeof(struct node));
        
        if(newNode == NULL){
            printf("Memory allocation failed!!!");
            exit(1);
        }
        
        printf("Enter the value of %dth node: ", i);
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;
        if(head == NULL){
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    
}

void insertAtBeginning(int value){
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("Memory allocation failed!!!");
        exit(1);
    } else {
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        printf("Node inserted successfully!!!\n");
    }
}

void deleteFromBeginning(){
    struct node *temp;
    temp = head;
    if(temp == NULL){
        printf("Linked list is empty.");
        return;
    } else {
        head = head->next;
        free(temp);
    }
}

void insertAtAnyPos(int pos, int val){
    int i;
    struct node *newNode, *temp, *pre;
    newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("Memory allocation failed!!!");
        exit(1);
    }
    newNode->data = val;
    temp = head;
    if(pos == 1){
        newNode->next = head;
        head = newNode;
        printf("Node inserted successfully!!!\n");
        return;
    }
    for(i=1;i<pos && temp !=NULL;i++){
        pre = temp;
        temp = temp->next;
    }
    if(temp == NULL && i<pos){
        printf("position not found!!");
        return;
    }
    pre->next = newNode;
    newNode->next = temp;
    printf("Node inserted successfully!!!\n");
}

void deleteFromAnyPos(int pos){
    struct node *temp, *pre;
    int i;
    if(head == NULL){
        printf("Linked list is empty.");
        return;
    }   
    temp = head;
    if(pos == 1){
        head = temp->next;
        free(temp);
        return;
    }
    for(i=1;i<pos && temp != NULL;i++){
        pre = temp;
        temp = temp->next;
    }
    pre->next = temp->next;
    free(temp);
    printf("Node deleted successfully!!!");
}

void displayNode(){
    struct node *temp = head;
    if(temp == NULL){
        printf("Linked list is empty.");
        return;
    }
    printf("\nLinked list is: \n");
    while( temp != NULL){
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}

int main(){
    int n, value, pos, val, choice;
    
    printf("---------------------------------------------\n");
	printf("                        MENU               \n");
	printf("---------------------------------------------\n");
	printf("1. Insert multiple nodes into the linked list\n2. Insert at the beginning of the linked list\n");
	printf("3. Delete the first node from the linked list\n4. Insert a node at any position\n5. Delete a node from any position\n");
	printf("6. Display the linked list\n7. Exit");

    
    while(1){
        printf("\nEnter your choice: \n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the size of linked list: \n");
                scanf("%d", &n);
                insertNode(n);
                break;
            case 2:
                printf("\nEnter the value of 1st node of linked list: \n");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 3:
                printf("\nDeleting 1st node from linked list: \n");
                deleteFromBeginning();
                break;
            case 4:
                printf("\nEnter the position you want to insert a new node: \n");
                scanf("%d", &pos);
                printf("Enter the value of the node: \n");
                scanf("%d", &val);
                insertAtAnyPos(pos, val);
                break;
            case 5:
                printf("\nEnter the position you want to delete a node: \n");
                scanf("%d", &pos);
                deleteFromAnyPos(pos);
                break;
            case 6:
                displayNode();
                break;
            case 7:
                printf("Exiting the program...\n");
                exit(0);
                break;
            default:
                printf("Wrong choice. Try again!!!");
                break;
                
        }
    }
    
    return 0;
}
