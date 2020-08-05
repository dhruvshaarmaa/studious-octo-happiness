#include<iostream>
using namespace std;
class LinkedList
{
	public:
	int val;
	LinkedList* next;
	LinkedList(int val)
	{
		this->val=val;
		this->next=NULL;
	}
};
LinkedList* createList(int n)
{
	LinkedList *head,*p;
	int val;
	if(n==0)
	{
		return NULL;
	}
	cin>>val;
	head=p=new LinkedList(val);
	for(int i=1;i<n;i++)
	{
		cin>>val;
		p->next=new LinkedList(val);
		p=p->next;
	}
	return head;
}
LinkedList* kAppend(LinkedList* head,int k,int n)
{
	LinkedList *temp=head,*p=head;
	int i=1;
	if(head==NULL or k==0 )
    {
        return head;
    }
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}

	while(i<n-k)
	{
		p=p->next;
		i++;
	}
	LinkedList* newHead=p->next;
	p->next=NULL;
	temp->next=head;
	return newHead;
}
int main() {
	int n,k;
	cin>>n;
	LinkedList* head=NULL;
	head=createList(n);
	cin>>k;
	k=k%n;
	head=kAppend(head,k,n);
	while(head!=NULL)
	{
		cout<<head->val<<" ";
		head=head->next;
	}
	return 0;
}
