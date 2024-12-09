class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int arrlen = nums.size();
        
        if (arrlen == 1) {
            std::vector<bool> res(queries.size(), true);
            return res;
        }
        
        std::vector<int> sum(arrlen, 0);
        for (int ind = 1; ind < arrlen; ++ind) {
            sum[ind] = sum[ind - 1] + ((nums[ind] % 2) == (nums[ind - 1] % 2) ? 1 : 0);
        }
        
        std::vector<bool> res(queries.size());
        for (int j = 0; j < queries.size(); ++j) {
            int s = queries[j][0];
            int e = queries[j][1];
            int c = sum[e] - sum[s];
            res[j] = (c == 0);
        }
        
        return res;
    }
};