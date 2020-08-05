#include<bits/stdc++.h>
using namespace std;
const int N=10;
vector<vector<int>> edges(N);
vector<int> graph[N];
int source,destination,tourist;
void path(int mid)
{
    int vis[N]={0};
    int par[N]={0};
    for(auto x:graph) x.clear(); //fresh graph is made for each value of mid
    for(auto x:edges)
    {
        if(x[2]>=mid)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
    }
    // lexographical path between s and d
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > q;
    q.push({source,0});
    while(!q.empty())
    {
        pair<int,int> p=q.top();
        q.pop();
        int curr=p.first;
        int parent=p.second;
        vis[curr]=1;
        par[curr]=parent;
        if(curr==destination) break;
        for(auto x:graph[curr])
        {
            if(!vis[curr]) q.push({x,curr});
        }
    }
    vector<int> path;
    while(destination!=source)
    {
        path.push_back(destination);
        destination=par[destination];
    }
    path.push_back(source);
    reverse(path.begin(),path.end());
    for(auto x:path) cout<<x<<" ";
    cout<<endl;
}
bool bfs()
{
    //to find if path exist between source and destination
    int vis[N]={0};
    queue<int> q;
    q.push(source);
    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        vis[curr]=1;
        for(auto x:graph[curr])
        {
            if(!vis[x]) q.push(x);
        }
    }
    return vis[destination];
}
bool check(int mid)
{
    for(auto x:graph) x.clear(); //fresh graph is made for each value of mid
    for(auto x:edges)
    {
        if(x[2]>=mid)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
    }
    return bfs();
}
int main()
{
	int n,m,max_edge=0,min_edge=INT_MAX;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		max_edge=max(max_edge,w);
		//min_edge=min(min_edge,w);
		//edge list
		edges[i]={x,y,w};
	}
	cin>>source>>destination>>tourist;
	//binary search for minimum weighted edge so that
	//path between source and destination exist
	int start=0,end=max_edge;
	while(start<=end)
    {
        int mid=(start+end)/2;
        if(check(mid))
        {
            min_edge=mid;
            start=mid+1; //maximize
        }
        else
        {
            end=mid-1;
        }
    }
   // path(min_edge);
    cout<<min_edge<<endl;
    min_edge--;
    int trips=tourist/min_edge+(tourist%min_edge!=0); //if some tourists are left then 1 more trip will be there
    cout<<trips<<endl;
	return 0;
}
/*
7 10
1 2 30
1 3 15
1 4 10
2 4 25
2 5 60
3 4 40
3 6 20
4 7 35
5 7 20
6 7 30
1 7 99
*/
