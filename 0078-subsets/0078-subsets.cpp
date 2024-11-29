class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        dfs(nums, 0, {}, result);
        return result;
    }
private:
    void dfs(const vector<int>& nums, int s, vector<int>&& path, vector<vector<int>>& result) {
        result.push_back(path);
        for (int i = s; i < nums.size(); i++) {
            path.push_back(nums[i]);
            dfs(nums, i + 1, move(path), result);
            path.pop_back();
        }
    }
};