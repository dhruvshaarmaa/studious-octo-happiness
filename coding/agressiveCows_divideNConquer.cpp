#include<iostream>
#include<algorithm>
using namespace std;
bool isTrue(int arr[],int n,int cows,int minDistance)
{
	int cowsPlaced=1;
	int prevIndex=arr[0];
	for(int i=1;i<n;i++)
	{
	    int currIndex=arr[i];
	    int diff=currIndex-prevIndex;
		if(diff>=minDistance)
		{
			cowsPlaced++;
			prevIndex=currIndex;

			if(cowsPlaced==cows)
			{
				return true;
			}
		}
	}
	return false;
}
int agressiveCow(int arr[],int n,int cows)
{
	sort(arr,arr+n);
	int start=1;
	int end=arr[n-1]-arr[0];
	int ans=1;
	while(start<=end)
	{
		int mid=(start+end)/2;
		if(isTrue(arr,n,cows,mid))
		{
			ans=mid;
			start=mid+1;
		}
		else
		{
			end=mid-1;
		}
	}
	return ans;
}
int main() {
	int n,c,arr[100000];
	cin>>n>>c;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<agressiveCow(arr,n,c);
	return 0;
}
