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

void SelectSort(int arr[],int len)
{
	for(int i=0;i<len;i++){
		int k = i;
		for(int j=k+1;j<len;j++){
			if(arr[j] < arr[k]){
				k = j;
			}
		}
		if(i != k)
			Swap(arr[i],arr[k]);
	}
}

int main(int argc,char *argv[])
{
	int arr[]={5,9,3,8,0,2,3};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	SelectSort(arr,size);
	for(int i=0;i<size;i++)
		cout << arr[i] << ' ';
	cout << endl;
	return 0;
}
