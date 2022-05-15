class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        
        for(int i=0;i<nums.size();i++)
        {
            int maxl=0;
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                    maxl=max(maxl,dp[j]);
            }
            dp[i]=maxl+1;
        }
        
        int res=*max_element(dp.begin(),dp.end());
        return res;
    }
};