#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

int queue[SIZE], front = -1, rear = -1;

void enQueue(int value){
	if(rear == SIZE - 1){
		printf("Queue is full!!! Insertion is not possible.\n");
	} else{
		if(front == -1){
			front = 0;
		}
		rear++;
		queue[rear] = value;
		printf("Value inserted successfully!!!\n");
	}
}
void deQueue(){
	if(front == -1 || front > rear){
		printf("Queue is empty!!! Deletion is not possible.\n");
	} else {
		printf("Deleted: %d\n", queue[front]);
		front++;
		if(front > rear){
			front = rear = -1;
		}
	}
}
void display(){
	if(rear == -1){
		printf("Queue is empty!!!\n");
	} else {
		int i;
		printf("Queue elements are: \n");
		for(i=front;i<=rear;i++){
			printf("%d\t", queue[i]);
		}
	}
}

int main(){
	int value, choice;
	while(1){
		printf("\n***** MENU *****\n");
		printf("1. Insertion\n2. Deletion\n3. Display\n4.Exit");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1: 
				printf("Enter the value to be insert:\n");
				scanf("%d", &value);
				enQueue(value);
				break;
			case 2: 
				deQueue();
				break;
			case 3: 
				display();
				break;
			case 4: 
				exit(0);
			default: 
				printf("Wrong choice!!! Try again!!!\n");
		}
	}
	return 0;
}
