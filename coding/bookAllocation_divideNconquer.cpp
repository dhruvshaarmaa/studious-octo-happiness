#include<iostream>
using namespace std;
bool isTrue(int arr[],int n,int m,int maximumPages)
{
	int noOfPages=0;
	int students=1;
	for(int i=0;i<n;i++)
	{
		noOfPages+=arr[i];
		if(noOfPages>maximumPages)
		{
			students++;
			noOfPages=arr[i];
			if(students>m)
			{
				return false;
			}
		}
	}
	return true;
}
int bookAllocation(int arr[],int n,int m)
{
	int minPages=arr[n-1];
	int maxPages=0;
	for(int i=0;i<n;i++)
	{
		maxPages+=arr[i];
	}
	int start=minPages;
	int end=maxPages;
	int ans=maxPages;
	while(start<=end)
	{
		int mid=start+(end-start)/2;
		if(isTrue(arr,n,m,mid))
		{
			ans=mid;
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
	int test,arr[100],m,n;
	cin>>test;
	for(int i=0;i<test;i++)
	{
		cin>>n>>m;
		for(int j=0;j<n;j++)
		{
			cin>>arr[j];
		}
		cout<<bookAllocation(arr,n,m)<<endl;
	}
	/*
	//static allocation
	int a=10;
	int arr[10];
	char ch='k';
	//dynamic allocation
	int *b=new int(10);
	//cout<<*b;

	int n=5;
	//cin>>n;
	int *brr=new int[n];
	for(int i=0;i<n;i++)
    {
        brr[i]=i+1;
    }
    for(int i=0;i<n;i++)
    {
        cout<<brr[i]<<" ";
    }
    //cout<<sizeof(arr);
    //cout<<sizeof(brr);
	delete [] brr;
	delete b;
	cout<<"Deleted"<<endl;
	*/
	return 0;
}
