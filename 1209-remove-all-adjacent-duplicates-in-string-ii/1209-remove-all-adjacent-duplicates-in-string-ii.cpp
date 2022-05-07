class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<char>st;
        
        int cnt=0;
        for(int i=0;i<s.size();i++)
        {
            if(st.empty())
            {
                st.push(s[i]);
                cnt=1;
            }
            else if(st.top()!=s[i]) //unmatched element
            {
                st.push(s[i]);
                cnt=1;
            }
            else if(st.top()==s[i] && cnt!=0)
            {
                st.push(s[i]);
                cnt++;
            }
            else if(st.top()==s[i] && cnt==0) //matching element after deletion
            {
                int t=0;
                stack<char>temp;
                while(!st.empty() && st.top()==s[i])
                {
                    temp.push(st.top());
                    st.pop();
                    t++;
                }
            
                while(!temp.empty())
                {
                    st.push(temp.top());
                    temp.pop();
                }
                
                st.push(s[i]);
                cnt=t+1;
            }
            if(cnt==k)
            {
                while(cnt)
                {
                    st.pop();
                    cnt--;
                }
            }
        }
        string res="";
        while(!st.empty())
        {
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};