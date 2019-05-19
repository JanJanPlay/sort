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

void BubbleSort(int arr[],int len)
{
	for(int i=0;i<len;i++){
		for(int j=0;j<len-i-1;j++){
			if(arr[j]>arr[j+1])
				Swap(arr[j],arr[j+1]);
		}
	}
}

int main(int argc,char *argv[])
{
	int arr[]={5,9,1,2,5,9,3,2};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	BubbleSort(arr,size);

	for(int i=0;i<size;i++)
		cout << arr[i] << ' ';
	cout << endl;
	return 0;
}
