#include<bits/stdc++.h>
using namespace std;
const int N=100;
vector<int> graph[N];
int vis[N]={};
//O(N)
void dfs(int root)
{
    cout<<root<<endl;
    vis[root]=1;
    for(auto x:graph[root])
    {
        if(!vis[x])
        {
            dfs(x);
        }
    }
}
//dfs without using visited array
void dfs_tree(int root,int parent)
{
    cout<<root<<endl;
    for(auto x:graph[root])
    {
        if(x!=parent)
        {
            dfs_tree(x,root);
        }
    }
}
//path from node to root node
int parent[100]={};
void path(int source,int par)
{
    parent[source]=par;
    for(auto x:graph[source])
    {
        if(x!=par) path(x,source);
    }
}
//depth of each node
int depth[100]={};
void depthFind(int source,int par_depth)
{
    vis[source]=1;
    depth[source]=par_depth;
    for(auto x:graph[source])
    {
        if(!vis[x]) depthFind(x,par_depth+1);
    }
}
//subTree Size
int size[100]={};
int subTreeSize(int root)
{
    vis[root]=1;
    //plus 1 for my node count
    int count=1;
    for(auto x:graph[root])
    {
        if(!vis[x])
        {
            count+=subTreeSize(x);
        }
    }
    size[root]=count;
    return count;
}
//height
int height[100];
void height1(int root,int par)
{
    height[root]=-1;
    for(auto x:graph[root])
    {
        if(x!=par)
        {
            height1(x,root);
            height[root]=max(height[root],height[x]);
        }
    }
    height[root]++;
}
int main() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    subTreeSize(1);
    for(int i=1;i<=n;i++)
    {
        cout<<i<<"->";
        /*while(curr!=0)
        {
            cout<<curr<<" ";
            curr=parent[curr];
        }*/
        cout<<size[i];
        cout<<endl;
    }
	return 0;
}
/*
7 6
1 2
1 3
2 4
2 5
5 6
3 7
*/
