#include<stdio.h>
#include<stdlib.h>

#define MAX 5

int top = -1, stack[MAX];

void push(){
	int val;
	if(top == MAX-1){
		printf("Stack is  full!!!");
	} else {
		printf("Enter the value of the elements: \n");
		scanf("%d", &val);
		top = top + 1;
		stack[top] = val;
	}
}

void pop(){
	if(top == -1){
		printf("Stack is empty\n");
	} else {
		printf("%d is deleted successfully!!!\n", stack[top]);
		top -= 1;
	}
}

void display(){
	int i;
	if(top == -1){
		printf("Stack is empty.\n");
	} else {
		printf("The stack is: \n");
		for(i=top;i>=0;--i){
			printf("%d\t", stack[i]);
		}
	}
	printf("\n");
}

int main(){
	int n;
	printf("----------------------------\n");
	printf("           MENU\n");
	printf("----------------------------\n");
	printf("1. Push\n2. Pop\n3. Display\n4. Exit");
	while(1){
		printf("Enter your choice: \n");
		scanf("%d", &n);
		switch(n){
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				printf("Exiting the program...\n");
				exit(0);
				break;
			deafult:
				printf("Wrong choice. Try again!!!\n");
		}
	}
	return 0;
}
