#include<iostream>
using namespace std;
void quickSort(int arr[],int start,int end)
{
    if(start>=end)
    {
        return;
    }

	int left=start;
	int right=end;
	int pivot=(start+end)/2;

	while(left<=right)
	{
		while(arr[left]<arr[pivot])
		{
			left++;
		}
		while(arr[right]>arr[pivot])
		{
			right--;
		}
		if(left<=right)
		{
			swap(arr[left],arr[right]);
			left++;
			right--;
		}
	}
	quickSort(arr,start,right);
	quickSort(arr,left,end);

}
int main() {
	int n,arr[100];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	quickSort(arr,0,n-1);
    for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}
