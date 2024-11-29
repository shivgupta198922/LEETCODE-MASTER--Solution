class Solution {
public:
    int minPathSum(vector<vector<int>>& v) {
        int i,j,n=v.size(),m=v[0].size();
        for(i=n-2;i>=0;i--)
            v[i][m-1]+=v[i+1][m-1];
        for(i=m-2;i>=0;i--)
            v[n-1][i]+=v[n-1][i+1];

        for(i=n-2;i>=0;i--) {
            for(j=m-2;j>=0;j--)
            v[i][j]+=min(v[i+1][j],v[i][j+1]);
        }
        return v[0][0];
    }
};