#include<bits/stdc++.h>
using namespace std;

//solution using dynamic programming

//Solution by Saurav Mishra
//Time-> O(n)
//space-> O(n)

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int x;
		cin>>x;
		vector<int> nums(n);
		for(int i=0;i<n;i++)
		{
			cin>>nums[i];
		}
        vector<int> res(n-x+1,0);
        
        if(x==n)
        {
        	cout<<*max_element(nums.begin(),nums.end())<<endl;
        	continue;
        }
        vector<int> left(n,0),right(n,0);
        left[0]=nums[0];
        right[n-1]=nums[n-1];
        for(int i=1;i<n;i++)
        {
            if(i%x==0)
                left[i]=nums[i];
            else
                left[i]=max(nums[i],left[i-1]);
            int j=n-1-i;
            if((j+1)%x==0)
                right[j]=nums[j];
            else
                right[j]=max(nums[j],right[j+1]);
        }
        for(int i=0;i<res.size();i++)
        {
            res[i]=max(left[i+x-1],right[i]);
        }
        for(int i=0;i<(int) res.size();i++)
        {
        	cout<<res[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}