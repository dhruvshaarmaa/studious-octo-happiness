#include<iostream>
using namespace std;
void balance(string ans,int leftCount,int rightCount,int n)
{
	if(rightCount==n)
	{
		cout<<ans<<endl;
		return;
	}

		//right
	if(leftCount>rightCount)
	{
		balance(ans+')',leftCount,rightCount+1,n);
	}
	//left
	if(leftCount<n)
	balance(ans+'(',leftCount+1,rightCount,n);

}
int main() {
	int n;
	cin>>n;
	balance("",0,0,n);
	return 0;
}
