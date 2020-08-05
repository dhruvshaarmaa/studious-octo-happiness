#include<iostream>
using namespace std;
void merge(int arr[],int start,int end)
{
	int mid=(start+end)/2;
	int temp[end-start+1];
	int i=start;
	int j=mid+1;
	int k=0;

	while(i<=mid && j<=end)
	{
		if(arr[i]<arr[j])
		{
			temp[k]=arr[i];
			k++;
			i++;
		}
		else
		{
			temp[k]=arr[j];
			j++;
			k++;
		}
	}
	while(i<=mid)
	{
		temp[k]=arr[i];
		i++;
		k++;
	}
	while(j<=end)
	{
		temp[k]=arr[j];
		j++;
		k++;
	}
	int pos=0;
	for(int i=start;i<=end;i++)
	{
		arr[i]=temp[pos];
		pos++;
	}
}
void mergeSort(int arr[],int start,int end)
{
	if(start==end)
	{
		return;
	}

	int mid=(start+end)/2;
	mergeSort(arr,start,mid);
	mergeSort(arr,mid+1,end);

	merge(arr,start,end);
}
int main() {
	int n,arr[100];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	mergeSort(arr,0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}
