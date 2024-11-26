class Solution {
public:

    bool isMatch (string s, string p) {
        int m = s.length();
        int n = p.length();
        vector<vector<bool>> dp (m + 1, vector<bool> (n + 1, false));
        bool current_match = false;
        dp[m][n] = true;
        char pchar = p[n - 1];
        bool dchar = false;
        bool schar = false;
        for (int j = n - 1; j >= 0; j--) {
            pchar = p[j];
            if (pchar == '*') {
                schar = true;
                continue;
            }
            dchar = (pchar == '.');
            for (int i = m; i >= 0; i--) {
                if (i < m) current_match = (dchar || (pchar == s[i]));
                else current_match = false;
                if (schar) {
                    if (dp[i][j + 2]) dp[i][j] = true;
                    else if (current_match) {
                        if (i < m) dp[i][j] = dp[i + 1][j];
                    }
                }
                else {
                    if (current_match) {
                        if (i < m) dp[i][j] = dp[i + 1][j + 1];
                    }
                }
            }
            schar = false;
        }
        return dp[0][0];
    }

};