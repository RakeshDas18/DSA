#include<stdio.h>

int main() {
    int arr[100], i, n, item;
    printf("Enter the number of elements: \n");
    scanf("%d", &n);
    printf("Write the value of the elements in order: \n");
    for(i = 0; i < n; i++) {
        printf("Enter the value of %d elements: \n", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Enter the number you want to search: \n");
    scanf("%d", &item);
    int high = n - 1;
    int low = 0;
    int mid = (high + low) / 2;
    while(low <= high){
    	if(arr[mid] < item){
    		low = mid + 1;
		} else if (arr[mid] == item){
			printf("%d is found at %d", item, mid + 1);
			break;
		} else {
			high = mid - 1;
		}
		mid = (low+high)/2;
	}
	if(low > high){
		printf("%d is not found! Try again!!!", item);
	}
    return 0;
}
