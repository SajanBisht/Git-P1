#include<stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
int count(int *arr,int size,int key){

int count=0;
for(int i=0;i<size;i++){
int j=i+1;
while(j<size){
if(arr[j]-arr[i]==key)
	{count++;
	j++;
	i++;
	}
else if(arr[j]-arr[i]<key)
	j++;
else
	i++;
}
}
printf("Count - %d",count);
return 0;
}
int main(){
int size,key;

printf("Enter size of array");
scanf("%d",&size);
int arr[size];

printf("Enter element of array");
for(int i=0;i<size;i++)
scanf("%d",&arr[i]);

printf("Enter key");
scanf("%d",&key);

qsort (arr, sizeof(arr)/sizeof(*arr), sizeof(*arr), comp);
count(arr,size,key);
}

