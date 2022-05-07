class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        
        for(int i=0;i<s.size();i++) //empty stack
        {
            if(st.empty())
            {
                st.push(make_pair(s[i],1));
            }
            else if(st.top().first!=s[i]) // unmatched top
            {
                st.push(make_pair(s[i],1));
            }
            else if(st.top().first == s[i])
            {
                int t=st.top().second;
                st.push(make_pair(s[i],t+1));
                
                if(st.top().second==k)
                {
                    int l=k;
                    while(l)
                    {
                        st.pop();
                        l--;
                    }
                }
            }
        }
        string res="";
        while(!st.empty())
        {
            res+=st.top().first;
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};