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
			}
		}
	}
	return curr_xor;
}
int main() {

    trie *head=new trie();
    vector<int> v{3,10,5,25,2,8};
    for(int j=0;j<v.size();j++)
    {
        insert(v[j],head);
    }
    int ans=findMaxXor(5,head);
    cout<<ans<<endl;
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
