#include<iostream>
#include<queue>
using namespace std;
int importanceOfTime(queue<int> q,int ideal[],int n)
{
	int time=0;
	for(int i=0;i<n;i++)
	{
		if(ideal[i]==q.front())
		{
			time++;
			q.pop();
		}
		else
		{
			while(ideal[i]!=q.front())
			{
				q.push(q.front());
				q.pop();
				time++;
			}
			time++;
			q.pop();
		}
	}
	return time;
}
int main() {
	queue<int> q;
	int ideal[100000],n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int val;
		cin>>val;
		q.push(val);
	}
	for(int i=0;i<n;i++)
	{
		cin>>ideal[i];
	}
	cout<<importanceOfTime(q,ideal,n)<<endl;
	return 0;
}
