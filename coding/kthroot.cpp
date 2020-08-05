#include<iostream>
#include<cmath>
using namespace std;
long long int kthRoot(long long int n,long long int k)
{
	long long int start=1;
	long long int end=n;
	long long int ans=0;
	while(start<=end)
    {
        long long int mid=start-(start-end)/2;
        if(pow(mid,k)<=n)
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
	int test;
	long long int n,k;
	cin>>test;
	for(int i=0;i<test;i++)
	{
		cin>>n>>k;
		cout<<kthRoot(n,k)<<endl;
	}

	return 0;
}
