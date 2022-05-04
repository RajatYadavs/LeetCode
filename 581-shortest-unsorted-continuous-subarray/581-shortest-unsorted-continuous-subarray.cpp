class Solution {
public:
     int findUnsortedSubarray(vector<int>& nums) {
         int mini=nums[0],maxi=nums[nums.size()-1];
         
         int l=-1,r=0;
         for(int i=1;i<nums.size();i++)
         {
             if(mini>nums[i])
             {
                 l=i; //left most unsettled
             }
             else
                 mini=nums[i];
         }
         for(int i=nums.size()-2;i>=0;i--)
         {
             if(maxi<nums[i])
             {
                 r=i;
             }
             else
                maxi=nums[i];
         }
         return l-r+1;
    }
};