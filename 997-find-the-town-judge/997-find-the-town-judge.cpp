class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,int>hm;
        unordered_map<int,vector<int>>t;
        for(int i=0;i<trust.size();i++)
        {
           hm[trust[i][1]]++;
           t[trust[i][0]].push_back(trust[i][1]);
        }
        for(int i=1;i<=n;i++)
        {
            if(t.find(i)==t.end() && hm[i]==n-1)
                return i;
        }
        return -1;
    }
};