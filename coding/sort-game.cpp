#include<iostream>
#include<string>
using namespace std;
void bubblesort(int arr[],int n,string str[])
{
    for(int i=0;i<n-1;i++)
    {
        int flag=1;
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j]<arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                swap(str[j],str[j+1]);
                flag=0;
            }
        }
        if(flag==1)
        {
            break;
        }
    }
}

void sortGame(int arr[],int n,string str[])
{
    for(int i=0;i<n-1;i++)
    {
        int flag=1;
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j]<arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                swap(str[j],str[j+1]);
                flag=0;
            }
            if(arr[j]==arr[j+1])
            {
                if(str[j]>str[j+1])
                {
                    swap(arr[j],arr[j+1]);
                    swap(str[j],str[j+1]);
                }
            }
        }
        if(flag==1)
        {
            break;
        }
    }

}
int main() {
    int n,maxSal,arr[100];
    string str[100];
    cin>>maxSal;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>str[i];
        cin>>arr[i];
    }
    sortGame(arr,n,str);

    for(int i=0;i<n;i++)
    {
        if(arr[i]>=maxSal)
        {
            cout<<str[i]<<" "<<arr[i]<<endl;
        }
    }
    return 0;
}
