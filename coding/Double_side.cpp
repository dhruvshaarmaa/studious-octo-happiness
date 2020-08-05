#include <iostream>

using namespace std;
int main()
{
    int num;
    cin>>num;
    int mid=(num/2)+1;
    for(int i=1;i<=mid;i++)
    {
        if(i==1)
        {
            for(int spaces=num-1;spaces>=1;spaces--)
            {
                  cout<<"  ";
            }
            cout<<1<<" ";
        }
        else{

      for(int spaces=num-2*i+1;spaces>=1;spaces--)
      {
          cout<<"  ";
      }
      for(int dec=i;dec>=1;dec--)
      {
          cout<<dec<<" ";
      }
      for(int space2=2*(i-1)-1;space2>=1;space2--)
      {
          cout<<"  ";
      }
       for(int inc=1;inc<=i;inc++)
      {
          cout<<inc<<" ";
      }

        }
     cout<<'\n';
    }

     for(int i=mid-1;i>=1;i--)
    {
        if(i==1)
        {
            for(int spaces=num-1;spaces>=1;spaces--)
            {
                  cout<<"  ";
            }
            cout<<1;
        }
        else{

      for(int spaces=num-2*i+1;spaces>=1;spaces--)
      {
          cout<<"  ";
      }
      for(int dec=i;dec>=1;dec--)
      {
          cout<<dec<<" ";
      }
      for(int space2=2*(i-1)-1;space2>=1;space2--)
      {
          cout<<"  ";
      }
       for(int inc=1;inc<=i;inc++)
      {
          cout<<inc<<" ";
      }

        }
     cout<<'\n';
    }
    return 0;
}
