#include<iostream>
#include<stack>
#include<vector>
using namespace std;
void pile(stack<int> &s,stack<int> &a1,stack<int> &b1,int q)
{
	int divisor=q;
	while(!s.empty())
	{
		if(s.top()%divisor==0)
		{
			b1.push(s.top());
			s.pop();
		}
		else
		{
			a1.push(s.top());
			s.pop();
		}
	}
	while(!b1.empty())
	{
		cout<<b1.top()<<endl;
		b1.pop();
	}
	s=a1;
	while(!a1.empty())
	{
		a1.pop();
	}

}
int main() {
	stack<int> s,a,b;
	vector<int> v;
    v.push_back(2);
    v.push_back(3);
    for(int i = 5; i <= 10000; i++)
    {
        int no = 0;
        for(int j = 2; j*j <= i; j++)
        {
            if(i%j == 0)
                no = 1;
        }
        if(!no)
            v.push_back(i);
    }

	int q,n;
    cin>>n>>q;
	for(int i=0;i<n;i++)
	{
		int val;
		cin>>val;
		s.push(val);
	}
	for(int i=0;i<q;i++)
	{
		int prime=v[i];
		pile(s,a,b,prime);
	}
	while(!s.empty())
	{
		cout<<s.top()<<endl;
		s.pop();
	}
	//cout<<ithPrime(5);
	return 0;
}
