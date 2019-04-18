#include "stdio.h"

void PrintArr(int arr[],int left,int right,
				const char *begin=NULL,
				const char *end=NULL)
{
	if(begin)
		printf("%s\n",begin);
	for(int i=left;i<right;i++)
		printf("%d ",arr[i]);
	printf("\n");
	if(end)
		printf("%s\n",end);
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
	bool change = false;
	int ref = arr[i];

	while(j>i){
		while(arr[j]>=ref)
			j--;
		if(j>i){
			Swap(arr[i],arr[j]);
			change = true;
		}
		else
			break;

		while(arr[i]<=ref)
			i++;
		if(j>i){
			Swap(arr[i],arr[j]);
			change = true;
		}
	}
	if(change)
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
	int arr[] = {5,6,7,8,9,1,2,3,4};
	int length = sizeof(arr)/sizeof(arr[0]);

	PrintArr(arr,0,length,"Start:","Process:");
	QuickSort(arr,0,length-1);
	PrintArr(arr,0,length,"Result:");
	
	return 0;
}
