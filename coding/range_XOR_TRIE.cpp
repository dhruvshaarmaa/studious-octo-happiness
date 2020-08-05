#include<bits/stdc++.h>
using namespace std;
class trie
{
	public:
	trie *left; //represents 0
	trie *right; //represents 1
	trie()
	{
		left=NULL;
		right=NULL;
	}
};
void insert(int num,trie* &head) //number insertion in trie
{
	trie *curr=head;
	for(int i=31;i>=0;i--)
	{
		int bit=(num>>i)&1;
		if(bit) //bit is 1
		{
			if(curr->right==NULL)
			{
				curr->right=new trie();
			}
			curr=curr->right;
		}
		else
		{
			if(curr->left==NULL)
			{
				curr->left=new trie();
			}
			curr=curr->left;
		}
	}
}
int findMaxXor(int X,trie *head)
{
	trie *curr=head;
	int number=0;
	int curr_xor=0;
	for(int i=31;i>=0;i--)
	{
		int bit=(X>>i)&1;
		if(bit==0)
		{
			if(curr->right)
			{
				curr=curr->right;
				curr_xor+=pow(2,i);
				number+=pow(2,i); //Y contains 1 because X contains 0
			}
			else
			{
				curr=curr->left;
			}
		}
		else
		{
			if(curr->left)
			{
				curr=curr->left;
				curr_xor+=pow(2,i);
			}
			else
			{
				curr=curr->right;
				number+=pow(2,i);//Y contains 1 although X contains 1 because 0 not available
			}
		}
	}
	return number;
}
vector<int> v;
int main() {
	int q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		int type;
		cin>>type;
		if(type==0)
		{
			int val;
			cin>>val;
			v.push_back(val);
		}
		else
		{
		    //for(auto x:v) cout<<x<<" ";
		    cout<<endl;
			trie *head=new trie();
			int L,R,X,ans;
            cin>>L>>R>>X;
			for(int j=L-1;j<R;j++)
			{
				insert(v[j],head);
			}
			ans=findMaxXor(X,head);
			cout<<ans<<endl;
		}
	}

	return 0;
}
/*
5
0 3
0 5
0 10
0 6
1 1 4 6
*/
