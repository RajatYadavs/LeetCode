long long minCoin(int amount,vector<int>& coins,vector<long long>&dp)
{
    if(dp[amount]!=INT_MAX)
    {
        return dp[amount];
    }
        
    if(amount==0)
        return dp[0]=0;
    
    for(int i=0;i<coins.size();i++)
    {
        if(coins[i]<=amount)
            dp[amount]=min(dp[amount],1+minCoin(amount-coins[i],coins,dp));
    }
    if(dp[amount]==INT_MAX)
        return dp[amount]=INT_MAX-1;
    
    return dp[amount];
}
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int c=coins.size();
        vector<long long>dp(amount+1,INT_MAX);
        int t=minCoin(amount,coins,dp);
        cout<<t<<endl;
        if(t==INT_MAX || t==INT_MAX-1)
            return -1;
        return t;
    }
};