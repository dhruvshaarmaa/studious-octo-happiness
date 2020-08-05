#include<iostream>
#include<deque>
using namespace std;
void maxSlidingWindow(int arr[],int n,int k)
{
    deque<int> q;
    for(int i=0;i<k;i++)
    {
        while(!q.empty() and arr[i]>=arr[q.back()])
        {
            q.pop_back();
        }
        q.push_back(i);
    }
    for(int i=k;i<n;i++)
    {
        cout<<arr[q.front()]<<endl;
        if(!q.empty() and q.front()<=i-k)
        {
            q.pop_front();
        }
        while(!q.empty() and arr[i]>=arr[q.back()])
        {
            q.pop_back();
        }
        q.push_back(i);
    }
    cout<<arr[q.front()]<<endl;
}
int main() {
    int arr[10]={1,3,2,0,4,5,2},n=7;
    maxSlidingWindow(arr,n,3);
	return 0;
}
