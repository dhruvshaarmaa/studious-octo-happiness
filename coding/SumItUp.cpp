#include<iostream>
#include<vector>
#include<set>
#include<iterator>
#include<algorithm>
using namespace std;
set<vector<int>> s;
void sumItUp(int arr[],int n,int target,int start,int sum,vector<int> v)
{
	if(sum==target)
	{
	    s.insert(v);
		/*for(int i=0;i<v.size();i++)
		{
			cout<<v[i]<<" ";
		}
		cout<<endl;*/
		return;
	}
	if(start==n)
	{
		return ;
	}

	v.push_back(arr[start]);
	sumItUp(arr,n,target,start+1,sum+arr[start],v);
	v.pop_back();
	sumItUp(arr,n,target,start+1,sum,v);
}
int main() {
    int arr[20]={0},n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int target;
    cin>>target;
    vector<int> v;
    sort(arr,arr+n);
    sumItUp(arr,n,target,0,0,v);
    //set <vector<int>> :: iterator itr;
    for (auto itr = s.begin(); itr != s.end(); ++itr)
    {
        vector<int> v=*itr;
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
	return 0;
}
