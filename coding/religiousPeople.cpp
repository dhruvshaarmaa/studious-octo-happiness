#include<bits/stdc++.h>
using namespace std;
class dsu{
	public:
    vector<int> par;
	vector<int> size;
    int connected_components;
    dsu(int n)
    {
        par.resize(n);
		size.resize(n);
        for(int i=0;i<n;i++) par[i]=i;
		for(int i=0;i<n;i++) size[i]=1;
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
			size[superParent__y]+=size[superParent__x];
			size[superParent__x]=0;
            connected_components--;
        }
    }
};

int main() {
	long long n,m,a,b,t;
	cin>>t;
	for(int j=0;j<t;j++)
	{
		cin>>n>>m>>a>>b;
		dsu G(n+1);
		for(int i=0;i<m;i++)
		{
        	int x,y;
 	        cin>>x>>y;
 	        G.unite(x,y);
  		}
		if(a<=b) cout<<a*n<<endl;
		else
        {
            long long ncc=G.connected_components-1;
            long long ans=0;
            ans+=ncc*a;// temple build at each representative
            for(int i=1;i<=n;i++)
            {
                if(G.size[i])
                {
                    //cout<<ans<<" "<<G.par[sp]<<endl;
                    ans+=(G.size[i]-1)*b;
                }
            }
            cout<<ans<<endl;
        }
	}

	return 0;
}
/*
2
3 3 2 1
1 2
3 1
2 3
6 6 2 5
1 3
3 4
2 4
1 2
2 3
5 6
*/
