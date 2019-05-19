/*
Date: 2019-05-19
Author: Jan
*/
#include <iostream>
using namespace std;

void Merge(int arr[],int left,int mid,int right,int temp[])
{
	int i = left;
	int j = mid+1;
	int t = 0;
	while(i<=mid && j<=right){
		if(arr[i]<=arr[j])
			temp[t++] = arr[i++];
		else
			temp[t++] = arr[j++];
	}

	while(i<=mid)
		temp[t++] = arr[i++];

	while(j<=right)
		temp[t++] = arr[j++];
	
	t = 0;

	while(left <= right)
		arr[left++] = temp[t++];
}

void SubSort(int arr[],int left,int right,int temp[])
{
	if(left < right){
		int mid = (left+right)/2;
		SubSort(arr,left,mid,temp);
		SubSort(arr,mid+1,right,temp);
		Merge(arr,left,mid,right,temp);
	}
}

void MergeSort(int arr[],int len)
{
	int *temp = new int(len);
	SubSort(arr,0,len-1,temp);
	//if(temp)
	//	free(temp);
}

int main(int argc,char *argv[])
{
	int arr[] = {6,1,4,9,4,7,8,3,5};
	int size = sizeof(arr)/sizeof(arr[0]);

	MergeSort(arr,size);

	for(int i=0;i<size;i++)
		cout << arr[i] << ' ';
	cout << endl;
	return 0;
}
