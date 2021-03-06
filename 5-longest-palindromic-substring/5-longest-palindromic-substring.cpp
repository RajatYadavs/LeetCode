class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,false)); //DP matrix for tabulation
        
        for(int i=0;i<n;i++) // all matrix updated to true;
            dp[i][i]=true;
        
        int maxl=1;
        string res="";
        res+=s[0];
        
/*if(s[i] equals s[j] and s[i+1]s[j-1] is a palindrome then s[i] to s[j] is also a palindrome)*/
        for(int j=1;j<n;j++) 
        { 
            for(int i=0;i<j;i++)
            {
                if(i+1<n && s[i]==s[j] && (dp[i+1][j-1]==true || j==i+1))
                {
                    if(j-i+1>maxl)
                    {
                        maxl=j-i+1;
                        res=s.substr(i,maxl);
                    }
                    dp[i][j]=1;
                }
            }
        }
        return res;
    }
};