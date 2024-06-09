#include<stdio.h>

int main(){
    int arr[100], n, i, j, min, t;
    printf("Enter number of elements\n");
    scanf("%d", &n);
    printf("Enter %d integers\n", n);
    for (i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    for(i=0;i<(n-1);i++){
        min = i;
        for(j=i+1;j<n;j++){
            if(arr[j] < arr[min]){
                min = j; 
            }
        }
        t = arr[min]; 
        arr[min] = arr[i]; 
        arr[i] = t;
    }
    printf("Sorted list in ascending order:\n");
    for(i=0;i<n;i++){
        printf("%d\t", arr[i]);
    }
    return 0;
}
