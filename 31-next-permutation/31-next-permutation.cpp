class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int l=nums.size()-1;
        while(l>0)
        {
            if(nums[l]>nums[l-1])
            {
                int n=nums.size()-1;
                while(nums[n]<=nums[l-1])
                    n--;
                swap(nums[n],nums[l-1]);
                sort(nums.begin()+l,nums.end());
                return;
            }
            l--;
        }
        sort(nums.begin(),nums.end());
    }
};