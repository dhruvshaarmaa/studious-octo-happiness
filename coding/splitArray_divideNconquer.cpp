#include<iostream>
#include<string>
#include<vector>
using namespace std;
  bool isValid(vector<int>& nums,int n,int m,int maxPossibleSum)
    {
        int noOfPartitionsMade=1;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(sum>maxPossibleSum)
            {
                sum=nums[i];
                noOfPartitionsMade++;
                if(noOfPartitionsMade>m)
                {
                    return false;
                }
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int m) {
        int n=nums.size();
        int minSum=0;
        int maxSum=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==INT_MAX)
            {
                return INT_MAX;
            }
            maxSum+=nums[i];
            minSum=max(minSum,nums[i]);
        }
        int start=minSum;
        int end=maxSum;
        int ans=maxSum;
        while(start<=end)
        {
            int mid=start-(start-end)/2;
            if(isValid(nums,n,m,mid))
            {
                ans=mid;
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        return ans;
    }
int main() {
	vector<int> nums = {7,2,5,10,8};
	int m=2;
	//cin>>m;
	cout<<splitArray(nums,m);
	return 0;
}
