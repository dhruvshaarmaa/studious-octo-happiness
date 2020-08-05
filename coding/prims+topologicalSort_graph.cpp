#include<bits/stdc++.h>
using namespace std;
#define P pair<int,int>
vector<int> graph[100];
int vis[100];
vector<int> order;
//topological sort
void topological(int source)
{
    vis[source]=1;
    for(auto x:graph[source])
    {
        if(!vis[x]) topological(x);
    }
    order.push_back(source);
}
/*
int prims(int n)
{
    int mst=0;
    priority_queue<P,vector<P>,greater<P>> q;
    q.push({0,1});
    while(!q.empty())
    {
        P ele=q.top();
        q.pop();
        int curr=ele.second;
        int distance=ele.first;
        if(!vis[curr])
        {
            vis[curr]=1;
            mst+=distance;
            for(auto x:graph[curr])
            {
                if(!vis[x.first])
                {
                    q.push({x.second,x.first});
                }
            }
        }
    }
    return mst;
}
*/
int main() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        graph[x].push_back({y});
    }
    //cout<<prims(n);
    topological(1);
    reverse(order.begin(),order.end());
    for(auto x:order) cout<<x<<" ";
	return 0;
}
/*topo
6 7
1 2
1 3
2 5
3 4
4 5
4 6
6 5
*/
/* prims
4 5
0 1 1
0 2 1
0 3 2
1 2 3
2 3 4

*/
