/*
Date: 2019-05-19
Author: Jan
*/

#include <iostream>
using namespace std;

void Swap(int &a,int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void AdjustHeap(int arr[],int i,int len){
	int temp = arr[i];
	for(int k=i*2+1;k<len;k=k*2+1){
		if(k+1<len && arr[k]<arr[k+1]){
			k++;
		}
		if(arr[k]>temp){
			arr[i] = arr[k];
			i = k;
		}else
			break;
	}
	arr[i] = temp;
}

void HeapSort(int arr[],int len)
{
	//建立初始堆
	for(int i=len/2-1;i>=0;i--){
		AdjustHeap(arr,i,len);
	}
	//交换后需要重新调整堆
	for(int j=len-1;j>0;j--){
		Swap(arr[0],arr[j]);
		AdjustHeap(arr,0,j);
	}
}

int main(int argc,char *argv[])
{
	int arr[] = {7,8,6,2,0,3,4};
	int size = sizeof(arr)/sizeof(arr[0]);
	HeapSort(arr,size);
	for(int i=0;i<size;i++)
		cout << arr[i] << ' ';
	cout << endl;

	return 0;
}
