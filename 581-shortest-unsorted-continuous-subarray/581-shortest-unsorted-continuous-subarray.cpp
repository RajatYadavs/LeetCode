class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int s=-1,e=0;
        int mini=nums[0], maxi=nums[nums.size()-1];
        for(int i=1;i<nums.size();i++)
        {
            if(mini>nums[i])
            {
                s=i;
            }
            else
            mini=nums[i];
        }
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(maxi<nums[i])
            {
                cout<<maxi<<" "<<i<<endl;
                e=i;
            }
            else
            maxi=nums[i];
        }
        return s-e+1;
    }
};