#include<bits/stdc++.h>
using namespace std;
const int N=100;
vector<int> graph[N];
int vis[N]={};
//O(N)
void dfs(int root)
{
    vis[root]=1;
    for(auto x:graph[root])
    {
        if(!vis[x])
        {
            dfs(x);
        }
    }
}
void sameColour(int root,int colourNumber)
{
    vis[root]=colourNumber;
    for(auto x:graph[root])
    {
        if(!vis[x])
        {
            sameColour(x,colourNumber);
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
//detect cycle in undirected graph
bool cycle=0;
void cycleDetect(int root,int parent)
{
    vis[root]=1;
    for(auto x:graph[root])
    {
        if(!vis[x])
        {
            cycleDetect(x,root);
        }
        else if(x!=parent)
        {
            cycle=1;
        }
    }
}
//vis[n]=0 node is not visited
//vis[n]=1 node is in call stack
//vis[n]=2 node is visited and not in call stack
void cycleDetect_directed(int root)
{
    vis[root]=1;
    for(auto x:graph[root])
    {
        if(!vis[x])
        {
            cycleDetect_directed(x);
        }
        else if(vis[x]==1)
        {
            cycle=1;
        }
    }
    vis[root]=2;
}
int main() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
    }
    cycleDetect_directed(1);
    cout<<(cycle?"Cycle Found":"Cycle Not Found");
    /*int count=0;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            count++;
            sameColour(i,count);
            //cout<<i<<" "<<count<<endl;
        }
    }
    cout<<"No of Connected Components "<<count<<endl;
	*/

	return 0;
}
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

