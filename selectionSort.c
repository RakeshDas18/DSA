#include<stdio.h>

int main(){
	int arr[100], n, item, i, j, temp, min;
	printf("Enter the total number of elements: \n");
	scanf("%d", &n);
	printf("Enter %d elements: \n", n);
	for(i=0;i<n;i++){
		scanf("%d", &arr[i]);
	}
	printf("Before sorting: \n");
	for(i=0;i<n;i++){
		printf("%d\t", arr[i]);
	}
	for(i=0;i<(n-1);i++){
		min = i;
		for(j=i+1;j<n;j++){
			if(arr[min] > arr[j]){
				min = j;
			}
		}
		if(arr[min] != arr[i]){
    		temp = arr[i];
    		arr[i] = arr[min];
    		arr[min] = temp;
		}
	}
	printf("\nAfter sorting: \n");
	for(i=0;i<n;i++){
		printf("%d\t", arr[i]);
	}
	
	
	return 0;
}
