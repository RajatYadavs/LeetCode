void ways(int idx,int sum,vector<int>v,vector<vector<int>>&res,int k,int n)
{
    if(v.size()==k || sum>n)
    {
        if(sum==n)
        {
            res.push_back(v);
        }
        return;
    }
    
    if(idx<=9)
        ways(idx+1,sum,v,res,k,n);
     
    if(idx<=9)
    {
        v.push_back(idx);
        ways(idx+1,sum+idx,v,res,k,n);
        v.pop_back();
    }
}
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>v;
        vector<vector<int>>res;
        ways(1,0,v,res,k,n);
        
        return res;
    }
};

// 1,2,3,4,5,6,7,8,9