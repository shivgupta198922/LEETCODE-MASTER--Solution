class Solution {
public:
    set<string>ok;
    void backtrack(string &s, int &n, int start)
    {
        if(start == n)
        {
            ok.insert(s);
            return;
        }
        for(int i=start;i<n;i++)
        {
            if(isdigit(s[i])) 
            {
                backtrack(s, n, i+1);
            }
            else 
            {
                s[i] = toupper(s[i]);
                backtrack(s, n, i+1);
                s[i] = tolower(s[i]);
                backtrack(s, n, i+1);
            }
        }
    }
    vector<string> letterCasePermutation(string s) 
    {
        int n = s.size();
        backtrack(s, n, 0);
        return vector<string>(begin(ok), end(ok));
    }
};