#include<iostream>
using namespace std;
int pivotSearch(int arr[],int start,int end)
{
	if(start>end )
	{
		return -1;
	}

	int mid=(start+end)/2;
	if(arr[mid]>arr[mid+1] and mid<=end)
    {
        return mid;
    }
	if(arr[mid]>=arr[start])
	{
		return pivotSearch(arr,mid+1,end);
	}
	else
	{
		return pivotSearch(arr,start,mid-1);
	}
}
int main() {
	int n,arr[10];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<pivotSearch(arr,0,n-1);
	return 0;
}
