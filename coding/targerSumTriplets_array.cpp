#include<iostream>
using namespace std;

void insertion_sort(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        for(int j=i;j>0;j--)
        {
            if(arr[j]<arr[j-1])
            {
                swap(arr[j],arr[j-1]);
            }
            else
            {
                break;
            }
        }
    }
}
void targetSumTriplets(int arr[],int n,int target)
{
    for(int i=0;i<n;i++)
    {
        int left=i+1,right=n-1;
        while(left<right)
        {
            if(arr[i]+arr[left]+arr[right]==target)
            {
                cout<<arr[i]<<", "<<arr[left]<<" and "<<arr[right]<<endl;
                left++;
                right--;
            }
            else if(arr[i]+arr[left]+arr[right]>target)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
    }
}

int main() {
	int arr[100],n,target;
	cin>>n;
	for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cin>>target;
    insertion_sort(arr,n);
    targetSumTriplets(arr,n,target);

	return 0;
}
