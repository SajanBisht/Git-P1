#include<stdio.h>

int insertion(int *arr,int size){
for(int i=1;i<size;i++){
int j=i-1;
int count=1;
int swap=0;
int temp=arr[i];
	while(j>=0 && arr[j]>temp){
	arr[j+1]=arr[j];
	swap++;
	j--;
	count++;
	}
	arr[j+1]=temp;
	printf("i-%d\t",i);
	printf("compare-%d\t",count);
	printf("swap-%d\n",swap);
}
printf("array-\n");
for(int i=0;i<size;i++){
printf("%d",arr[i]);
}
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

insertion(arr,size);
}

