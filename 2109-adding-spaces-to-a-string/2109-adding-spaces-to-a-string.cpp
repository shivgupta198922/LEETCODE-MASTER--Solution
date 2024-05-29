class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) 
    {
        string ans="";
        int k=0;
        for(int i=0;i<s.length();i++)
        {
            if(k<spaces.size()&&i==spaces[k])
            {
                ans+=" ";
                ans+=s[i];
                k++;
            }
            else
            {
                ans+=s[i];
            }
        }
        return ans;
        
    }
};