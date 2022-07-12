class Solution {
    long long t1=0,t2=0,t3=0,t4=0;
    bool solve(int idx,long long t,vector<int>& matchsticks){
    if(t1>t || t2>t || t3>t || t4>t)
        return false;
    if(idx==matchsticks.size()){
        if(t1==t && t2==t && t3==t && t4==t)
            return true;
        return false;
    }
    t1+=matchsticks[idx];
    if(solve(idx+1,t,matchsticks))
        return true;
    t1-=matchsticks[idx];
    
    t2+=matchsticks[idx];
    if(solve(idx+1,t,matchsticks))
         return true;
    t2-=matchsticks[idx];
    
    t3+=matchsticks[idx];
    if(solve(idx+1,t,matchsticks))
         return true;
    t3-=matchsticks[idx];
    
    t4+=matchsticks[idx];
    if(solve(idx+1,t,matchsticks))
        return true;
    t4-=matchsticks[idx];
    
    return false;
}
public:
    bool makesquare(vector<int>& matchsticks) {
        long long sum=0;
        for(int c:matchsticks){
            sum+=c;
        }
        if(sum%4!=0)
            return false;
        long long t=sum/4;
        sort(matchsticks.rbegin(), matchsticks.rend());
        return solve(0,t,matchsticks);
    }
};