#include<iostream>
using namespace std;
void hanoi(int n,string src,string dest,string helper)
{
    //base case
    if(n==0)
    {
        return ;
    }

    hanoi(n-1,src,helper,dest);
    cout<<"Moving ring "<<n<<" from "<<src<<" to "<<dest<<endl;
    hanoi(n-1,helper,dest,src);

}

int main() {
	string A="A",B="B",C="C";
	int n;
	cin>>n;
	hanoi(n,A,B,C);
	return 0;
}
