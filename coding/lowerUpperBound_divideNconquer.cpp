#include<iostream>
using namespace std;
int lowerBound(int arr[],int n,int key)
{
	int start=0;
	int end=n-1;
	int ans=-1;
	while(start<=end)
	{
		int mid=start-(start-end)/2;
		if(arr[mid]==key)
		{
			end=mid-1;
			ans=mid;
		}
		else if(arr[mid]>key)
		{
			end=mid-1;
		}
		else
		{
			start=mid+1;
		}
	}
	return ans;
}
int upperBound(int arr[],int n,int key)
{
	int start=0;
	int end=n-1;
	int ans=-1;
	while(start<=end)
	{
		int mid=start-(start-end)/2;
		if(arr[mid]==key)
		{
			start=mid+1;
			ans=mid;
		}
		else if(arr[mid]>key)
		{
			end=mid-1;
		}
		else
		{
			start=mid+1;
		}
	}
	return ans;
}
int main() {
	int n,arr[100000],q,x;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cin>>q;
	for(int i=0;i<q;i++)
	{
		cin>>x;
		cout<<lowerBound(arr,n,x)<<" "<<upperBound(arr,n,x)<<endl;
	}
	return 0;
}
