int ways(int idx,int amount,vector<int>& coins,vector<vector<int>>&dp)
{
    if(amount==0)
        return dp[0][idx]=1;
    
    else if(idx==coins.size())
        return 0;
    
    else if(dp[amount][idx]!=-1)
        return dp[amount][idx];
    
    int t=0;
    
    if(coins[idx]<=amount)
        t=ways(idx,amount-coins[idx],coins,dp)+ways(idx+1,amount,coins,dp);
    
    return dp[amount][idx]=t;
}
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(),coins.end());
        vector<vector<int>>dp(amount+1,vector<int>(coins.size(),-1));
        int t=ways(0,amount,coins,dp);
        return t;
    }
};