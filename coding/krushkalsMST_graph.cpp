#include<bits/stdc++.h>
using namespace std;
const int N=20;
//vector<int> graph(N);
//vector<int> vis(N);
class dsu{
    public:
    vector<int> par;
    int connected_components;
    dsu(int n)
    {
        par.resize(n);
        for(int i=0;i<n;i++) par[i]=i;
        connected_components=n;
    }
    int get_superParent(int x)
    {
        if(x==par[x]) return x;
        else
        {
            //path compression
            return par[x]=get_superParent(par[x]);
        }
    }
    void unite(int x,int y)
    {
        int superParent__x=get_superParent(x);
        int superParent__y=get_superParent(y);
        if(superParent__x!=superParent__y)
        {
            par[superParent__x]=superParent__y;
            connected_components--;
        }
    }
};

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges(m);
    for(int i=0;i<m;i++)
    {
        int x,y,w;
        cin>>w>>x>>y;
        edges[i]={w,x,y};
    }
    sort(edges.begin(),edges.end());
    int mst=0;
    dsu G(n);
    for(int i=0;i<m;i++)
    {
        int w,x,y;
        x=edges[i][1];
        y=edges[i][2];
        w=edges[i][0];
        if(G.get_superParent(x)!=G.get_superParent(y))
        {
            G.unite(x,y);
            mst+=w;
        }
    }
    cout<<mst<<endl;
	//dsu G(5);
	//cout<<G.get_superParent(4);
	return 0;
}
/*
4 5
0 2 3
1 0 2
1 0 3
2 1 0
5 1 3
*/
