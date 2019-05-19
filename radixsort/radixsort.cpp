/*
Date: 2019-05-19
Author: Jan
*/

#include <iostream>
using namespace std;

int GetMax(int arr[],int len)
{
	int i,max;
	max = arr[0];
	for(i=0;i<len;i++)
		if(arr[i]>max)
			max = arr[i];
	return max;
}

void CountSort(int arr[],int len,int exp)
{
	int output[len];
	int i,buckets[10]={0};

	for(i=0;i<len;i++)
		buckets[(arr[i]/exp)%10]++;

	for(i=1;i<10;i++)
		buckets[i] += buckets[i-1];

	for(i=len-1;i>=0;i--){
		output[ buckets[ (arr[i]/exp)%10 ]-1 ]= arr[i];
		buckets[ (arr[i]/exp)%10 ]--;
	}

	for(i=0;i<len;i++)
		arr[i] = output[i];
}

void RadixSort(int arr[],int len)
{
	int exp;
	int max = GetMax(arr,len);

	for(exp=1;max/exp>0;exp*=10)
		CountSort(arr,len,exp);
}

int main(int argc,char *argv[])
{
	int arr[] = {123,896,567,389,90,5,222,766,78};
	int size = sizeof(arr)/sizeof(arr[0]);

	RadixSort(arr,size);

	for(int i=0;i<size;i++)
		cout << arr[i] << ' ';
	cout << endl;
	return 0;
}
