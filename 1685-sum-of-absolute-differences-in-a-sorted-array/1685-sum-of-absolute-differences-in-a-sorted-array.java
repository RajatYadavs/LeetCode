class Solution {
    public int[] getSumAbsoluteDifferences(int[] nums) {
        ArrayList<Integer>pf=new ArrayList<>();
        
        for(int i=0;i<nums.length;i++){
            if(i==0)
                pf.add(nums[i]);
            else{
                pf.add(pf.get(i-1)+nums[i]);
            }
        }
        int sum=pf.get(pf.size()-1);
        
        int[] res=new int[nums.length];
        for(int i=0;i<nums.length;i++){
            int t=((i+1)*nums[i]-pf.get(i));
            t+=sum-pf.get(i)-(nums.length-i-1)*nums[i];
            res[i]=t;
        }
        return res;
    }
}