/*
Date: 2019-05-18
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

void ShellSort(int arr[],int len)
{
	for(int gap = len/2;gap>0;gap/=2){
		for(int i=gap;i<len;i++){
			int j=i;
			while(j-gap>=0 && arr[j]<arr[j-gap]){			
				Swap(arr[j],arr[j-gap]);
				j-=gap;
			}
		}
	}
}

int main(int argc,char *argv[])
{
	int arr[] = {9,5,2,7,1,3};
	int size = sizeof(arr)/sizeof(arr[0]);

	ShellSort(arr,size);

	for(int i=0;i<size;i++)
		cout << arr[i] << ' ';
	cout << endl;
}
