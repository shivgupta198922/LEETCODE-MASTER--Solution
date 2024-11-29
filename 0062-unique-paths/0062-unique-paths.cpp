class Solution {
public:
    int uniquePaths(int m, int n) {
        int s=(m-1)+(n-1);
        int r=m-1;
        double ans=1;
        for(int i=1;i<=r;i++)
        {
            ans=ans*(s-r+i)/i;
        }
        return (int)ans;
    }
};