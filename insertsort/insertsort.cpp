#include <iostream>
using namespace std;

void Insert(int  arr[],int n)
{
	int key = arr[n];
	int i = n;
	while(arr[i-1] > key){
		arr[i] = arr[i-1];
		i--;
		if(i==0)
			break;
	}
	arr[i] = key;
}

void InsertSort(int arr[],int n)
{
	int i;
	for(i=1;i<n;i++){
		Insert(arr,i);
	}
}

int main(int argc,char *argv[])
{
	int arr[] = {6,9,1,3,5,8,10,3};
	int i;
	int size = sizeof(arr)/sizeof(arr[0]);
	InsertSort(arr,size);
	for(int i=0;i<size;i++)
		cout << arr[i] << endl;
	return 0;

}
