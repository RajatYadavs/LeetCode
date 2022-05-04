int Calculate(string &text1,string &text2,int y,int z,vector<vector<int>> &dp)
{
    if(y==-1 || z==-1)
        return 0;
    if(dp[y][z]!=-1)
        return dp[y][z];
    
    int t1=INT_MIN,t2=INT_MIN;
    if(text1[y]==text2[z])
        return dp[y][z]=1+Calculate(text1,text2,y-1,z-1,dp);
    
    else
    {
        t1=Calculate(text1,text2,y-1,z,dp);
        t2=Calculate(text1,text2,y,z-1,dp);
        
        return dp[y][z]=max(t1,t2);
    }
}
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int x=text1.size(); //point 1
        int y=text2.size(); //point 2
        
        vector<vector<int>>dp(x+1,vector<int>(y+1,-1)); //dp matrix
        return Calculate(text1,text2,x-1,y-1,dp);
    }
};