#include<bits/stdc++.h>
using namespace std;
//heap
class heap
{
public:
    vector<int> v;
    heap(vector<int> arr)
    {
        v=arr;
    }
    //min Heap
    //O(logN)
    void heapify(int index)
    {
        int left=2*index+1;
        int right=left+1;
        int minIndex=index;
        if(left<v.size() and v[left]<v[index])
        {
            minIndex=left;
        }
        if(right<v.size() and v[right]<v[minIndex])
        {
            minIndex=right;
        }
        if(minIndex!=index)
        {
            swap(v[minIndex],v[index]);
            heapify(minIndex);
        }
    }
    //O(N)
    void buildHeap()
    {
        int last_parent=(v.size()-2)/2;
        for(int i=last_parent;i>=0;i--)
        {
            heapify(i);
        }
    }
    //O(logN)
    void insert(int val)
    {
        v.push_back(val);
        int index=v.size()-1;
        int parent=(index-1)/2;
        while(index>0 and v[parent]>v[index])
        {
            swap(v[parent],v[index]);
            index=parent;
            parent=(index-1)/2;
        }
    }
    //O(1)
    int top()
    {
        return v[0];
    }
    //O(logN)
    void pop()
    {
        swap(v[0],v.back());
        v.pop_back();
        heapify(0);
    }
    void clear()
    {
        v.clear();
    }
    bool empty()
    {
        return v.empty();
    }
};
//O(NlogN)
void heapSort(vector<int> &arr)
{
    heap H(arr);
    //O(N)
    H.buildHeap();
    //O(NlogN)
    for(int i=0;i<arr.size();i++)
    {
        arr[i]=H.top();
        //O(logN)
        H.pop();
    }
}
int main() {
    vector<int> arr{4,3,6,1,2,0,8};
    heapSort(arr);
    for(auto x: arr) cout<<x<<" ";
	return 0;
}
