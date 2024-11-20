class Solution {
public:
    unordered_set<string>st;
    int len;
    vector<string> removeInvalidParentheses(string s) {
        len=s.length();
        vector<string>ans;
        int open=0,close=0;
        int c=0;
        stack<char>stk;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                stk.push(s[i]);
            }
            else if(s[i]==')')
            {
                if(!stk.empty() and stk.top()=='(')
                {
                    stk.pop();
                }
                else
                {
                    c++;
                }
            }
        }
        c+=(stk.size());
        cout<<c<<endl;
        string str="";
        fun(s,str,0,c);
        for(auto x:st)
        {
            ans.push_back(x);
        }
        if(ans.size()==0)
            return {""};
        return ans;
    }
    void fun(string &s,string &str,int idx,int &c)
    {
        if(str.length()==len-c)
        {
            //cout<<str<<endl;
            if(st.find(str)==st.end())
            {
                if(isvalid(str))
                {
                    st.insert(str);
                }
            }
            return;
        }
        if(idx>=s.length())
        {
            return;
        }
        str.push_back(s[idx]);
        fun(s,str,idx+1,c);
        str.pop_back();
        fun(s,str,idx+1,c);
    }
    bool isvalid(string &s)
    {
        stack<char>st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                st.push(s[i]);
            }
            else if(s[i]==')')
            {
                if(!st.empty() and st.top()=='(')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        if(st.size()>=1)
            return false;
        return true;
    }
};