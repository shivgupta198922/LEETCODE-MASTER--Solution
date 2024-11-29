class Solution {
public:
    vector<int> getRow(int n) {
        vector<int> nums;
        if (n == 0) return {1};
        vector<int> dp = {1}; 
        for (int i = 1; i <= n; i++) {
            vector<int> temp(i + 1, 1); 
            for (int j = 1; j < i; j++) {
                temp[j] = dp[j - 1] + dp[j]; 
            }
            dp = temp;
        }
        return dp; 
    }
};