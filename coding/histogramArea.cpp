#include<iostream>
#include<stack>
using namespace std;
int areaHistogram(int arr[],int n)
{
	int maxArea=0;
	stack<int> s;
	int i=0;
	while(i<n)
	{
		if(s.empty() or arr[s.top()]<=arr[i])
		{
			s.push(i);
			i++;
		}
		else
		{
			int currArea;
			int currHeight=arr[s.top()];
			int rightSmaller=i;
			s.pop();
			if(s.empty())
			{
				currArea=currHeight*rightSmaller;
			}
			else
			{
				int leftSmaller=s.top();
				int width=rightSmaller-leftSmaller-1;
				currArea=width*currHeight;
			}
			maxArea=max(currArea,maxArea);
		}
	}
	while(!s.empty())
		{
			int currArea;
			int currHeight=arr[s.top()];
			int rightSmaller=i;
			s.pop();
			if(s.empty())
			{
				currArea=currHeight*rightSmaller;
			}
			else
			{
				int leftSmaller=s.top();
				int width=rightSmaller-leftSmaller-1;
				currArea=width*currHeight;
			}
			maxArea=max(currArea,maxArea);
		}
	return maxArea;
}
int main() {
	int arr[10]={2,1,5,6,2,3},n=6;
	/*cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	*/
	cout<<areaHistogram(arr,n);
	return 0;
}
