int count(int pos,int l,int n,vector<vector<int>>&dp)
{
    if(pos==n)
        return dp[pos][l]=1;
    else if(dp[pos][l]!=-1)
        return dp[pos][l];
    
    int t=0;
    for(int i=l;i<5;i++)
    {
        t+=count(pos+1,i,n,dp);
    }
    return dp[pos][l]=t;
}
class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>>dp(n+1,vector<int>(5,-1));
        
        return count(0,0,n,dp);
    }
};