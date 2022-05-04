class Solution {
public:
    string intToRoman(int num) {
        int pos=1;
        string res="";
        stack<string>st;
        vector<char>symbol({'I','V','X','L','C','D','M'});
        while(num)
        {
            int p;
            if(pos==1)
            {
                p=0;
            }
            else if(pos==2)
            {
                p=2;
;           }
            else if(pos==3)
            {
                p=4;
            }
            else if(pos==4)
            {
                p=6;
            }
            
            int t=num%10;
            num/=10;
            
            string s="";
            
            if(t==1)
            {
                s+=symbol[p];
                st.push(s);
            }
            else if(t==2)
            {
                s+=symbol[p];
                s+=symbol[p];
                st.push(s);
            }
            else if(t==3)
            {
                s+=symbol[p];
                s+=symbol[p];
                s+=symbol[p];
                st.push(s);
            }
            else if(t==4)
            {
                s+=symbol[p];
                s+=symbol[p+1];
                st.push(s);
            }
            else if(t==5)
            {
                s+=symbol[p+1];
                st.push(s);
            }
            else if(t==6)
            {
                s+=symbol[p+1];
                s+=symbol[p];
                st.push(s);
            }
            else if(t==7)
            {
                s+=symbol[p+1];
                s+=symbol[p];
                s+=symbol[p];
                st.push(s);
            }
            else if(t==8)
            {
                s+=symbol[p+1];
                s+=symbol[p];
                s+=symbol[p];
                s+=symbol[p];
                st.push(s);
            }
            else if(t==9)
            {
                s+=symbol[p];
                s+=symbol[p+2];
                st.push(s);
            }
            
            pos++;
        }
        while(!st.empty())
        {
            res+=st.top();
            st.pop();
        }
        return res;
    }
};