void Generate(int pos,vector<int>nums,set<vector<int>>&permute)
{
    if(pos==nums.size())
    {
        permute.insert(nums);
    }
    
    for(int i=pos;i<nums.size();i++)
    {
        swap(nums[pos],nums[i]);
        Generate(pos+1,nums,permute);
        swap(nums[pos],nums[i]);
    }
}
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>permute;
        vector<int>res;
        
        Generate(0,nums,permute);
        
        vector<vector<int>>ans;
        for(auto itr=permute.begin();itr!=permute.end();itr++)
            ans.push_back(*itr);
        
        return ans;
    }
};