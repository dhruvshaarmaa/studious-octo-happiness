#include<bits/stdc++.h>
#define P pair<int,int>
using namespace std;
const int N=100;

//{node,weight}
vector<pair<int,int>> graph[N];
int vis[N]={};
/*void bfs(int source)
{
    queue<int> q;
    vis[source]=1;
    q.push(source);
    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        cout<<curr<<endl;
        for(auto x: graph[curr])
        {
            if(!vis[x])
            {
                vis[x]=1;
                q.push(x);
            }
        }
    }
}
vector<int> bfs_Distance(int source,int n)
{
    vector<int> distance(n+1,INT_MAX);
    distance[source]=0;
    queue<int> q;
    q.push(source);
    vis[source]=1;
    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        for(auto x: graph[curr])
        {
            if(!vis[x])
            {
                vis[x]=1;
                distance[x]=distance[curr]+1;
                q.push(x);
            }
        }
    }
    return distance;
}*/
//shortest path for weighted graph
vector<int> dijkstras(int source,int n)
{
    vector<int> dis(n+1);
    //heap is used instead of queue
    priority_queue<P,vector<P>,greater<P> > q;
    q.push({0,source});
    while(!q.empty())
    {
        P ele=q.top();
        q.pop();
        if(!vis[ele.second])
        {
            int curr=ele.second;
            int distance=ele.first;
            dis[curr]=distance;
            vis[curr]=1;
            for(auto x:graph[curr])
            {
                int weight=x.second;
                int dest_node=x.first;
                if(!vis[dest_node])
                {
                    q.push({distance+weight,dest_node});
                }
            }
        }
    }
    return dis;
}
int main() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        graph[x].push_back({y,w});
        graph[y].push_back({x,w});
    }
    vector<int> v(n+1);
    v=dijkstras(1,n);
    for(int i=1;i<=n;i++)
    {
        cout<<v[i]<<endl;
    }

	return 0;
}
//dijkstras
/*
6 9
1 2 5
1 3 2
2 3 1
2 4 8
2 5 1
3 5 2
4 5 3
4 6 2
5 6 5
*/
//cycle
/*
5 6
1 2
2 3
2 5
5 3
4 1
5 4

*/
/*
7 5
1 2
1 3
2 3
4 5
5 6
*/
/*
7 6
1 2
1 3
2 4
2 5
5 6
3 7
*/

