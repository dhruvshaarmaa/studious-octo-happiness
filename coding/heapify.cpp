#include<bits/stdc++.h>
using namespace std;
struct minHeap
{
    vector<int> v;
    minHeap(vector<int> a)
    {
        v=a;
    }
    void heapify(int i)
    {
        int parent=i;
        int min_idx=parent;
        int left=2*parent+1;
        int right=2*parent+2;
        if(left<=v.size()-1 and v[left]<v[min_idx])
        {
            min_idx=left;
        }
        if(right<=v.size()-1 and v[right]<v[min_idx])
        {
            min_idx=right;
        }
        if(min_idx!=parent)
        {
            swap(v[parent],v[min_idx]);
            heapify(min_idx);
        }
    }
    void heap()
    {
        int last_parent=(v.size()-2)/2;
        for(int i=last_parent;i>=0;i--)
        {
            heapify(i);
        }
//        for(auto x: v) cout<<x<<" ";
    }
    int top()
    {
        return v[0];
    }
    bool empty()
    {
        return v.empty();
    }
    void clear()
    {
        v.clear();
    }
    void pop()
    {
        swap(v[0],v.back());
        v.pop_back();
        heapify(0);
    }
    void push(int val)
    {
        v.push_back(val);
        int parent=(v.size()-2)/2;
        int idx=v.size()-1;
        while(idx>0 and v[parent]>v[idx])
        {
            swap(v[parent],v[idx]);
            idx=parent;
            parent=(idx-1)/2;
        }
    }
};
void heapSort(vector<int> &arr)
{
    minHeap H(arr);
    H.heap();
    for(int i=0;i<arr.size();i++)
    {
        arr[i]=H.top();
        H.pop();
    }
}
int main() {
    int n={5};
//    cin>>n;
    vector<int> arr{5,4,2,3,1};
//    for(int i=0;i<n;i++)
//    {
//        cin>>arr[i];
//    }
    minHeap H(arr);
    H.heap();
    cout<<H.top()<<endl;
    H.pop();
    cout<<H.top()<<endl;
    H.push(0);
    cout<<H.top()<<endl;
	heapSort(arr);
	for(auto x:arr) cout<<x<<" ";
	return 0;
}
