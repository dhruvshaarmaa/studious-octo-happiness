#include<iostream>
using namespace std;
bool isComplete(int arr[],int n,int k,int deadline)
{
	int noOfPainters=1;
	int timeTaken=0;
	for(int i=0;i<n;i++)
	{
		timeTaken+=arr[i];
		if(timeTaken>deadline)
		{
			noOfPainters++;
			timeTaken=arr[i];
			if(noOfPainters>k)
			{
				return false;
			}
		}
	}
	return true;
}
int painterProblem(int k,int t,int arr[],int n)
{
	int minTime=0;
	int maxTime=0;
	for(int i=0;i<n;i++)
	{
		maxTime+=arr[i];
		minTime=max(minTime,arr[i]);
	}
	int start=minTime;
	int end=maxTime;
	int ans=maxTime;
	while(start<=end)
	{
		int mid=(start+end)/2;
		if(isComplete(arr,n,k,mid))
		{
			end=mid-1;
			ans=mid;
		}
		else
		{
			start=mid+1;
		}
	}
	return t*ans;
}
int main() {
	int n,k,t,arr[100000];
	cin>>n>>k>>t;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<painterProblem(k,t,arr,n);
	return 0;
}
