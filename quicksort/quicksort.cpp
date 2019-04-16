#include "stdio.h"

void PrintArr(int arr[],int left,int right)
{
	for(int i=left;i<right;i++)
		printf("%d ",arr[i]);
	printf("\n");
}

void Swap(int &a,int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int Partition(int arr[],int left,int right)
{
	int i = left,j = right;
	int ref = arr[i];

	while(j>i){
		while(arr[j]>ref)
			j--;
		Swap(arr[i],arr[j]);

		while(arr[i]<ref)
			i++;
		Swap(arr[i],arr[j]);
	}
	PrintArr(arr,left,right+1);
	return i;
}

void QuickSort(int arr[],int left,int right)
{
	int i=left,j=right;
	int ref;
	if(right>left){
		ref = Partition(arr,i,j);

		QuickSort(arr,left,ref-1);
		QuickSort(arr,ref+1,right);
	}
}

int main(int argc,char *argv[])
{
	int arr[9] = {5,8,6,10,2,4,7,0,3};
	int length = sizeof(arr)/sizeof(arr[0]);

	printf("Start:\n");
	PrintArr(arr,0,length);
	printf("Process:\n");	
	QuickSort(arr,0,length-1);

	printf("Result:\n");
	PrintArr(arr,0,length);
	
	return 0;
}
