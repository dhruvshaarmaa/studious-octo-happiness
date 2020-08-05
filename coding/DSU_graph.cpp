#include<bits/stdc++.h>
using namespace std;
struct dsu{
    vector<int> par;
    int connected_components;
    void init(int n)
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

	return 0;
}
