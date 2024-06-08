#include<stdio.h>

int main(){
	int arr[100], i, n, item;
	printf("Enter the number of elements: \n");
	scanf("%d", &n);
	for(i=0;i<n;i++){
		printf("Enter the value of %d elements: \n", i+1);
		scanf("%d", &arr[i]);
	}
	printf("Enter the number you want to search: \n");
	scanf("%d", &item);
	for(i=0;i<n;i++){
		if(item == arr[i]){
			printf("%d is found at %d location.", item, i+1);
			break;
		}
	}
	if(i == n){
		printf("%d is not found!!!", item);
	}
	
	return 0;
}
