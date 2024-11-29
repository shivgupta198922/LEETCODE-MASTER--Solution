class Solution {
public:
    int n;
    vector<int>nums, path;
    vector<vector<int>>ans;
    void backtracking(int target, int start)
    {
        if(target == 0)
        {
            ans.push_back(path);
            return;
        }
        for(int i=start;i<n;i++)
        {
            if(nums[i] > target) break;
            if(i > start and nums[i] == nums[i-1]) continue;
            path.push_back(nums[i]);
            backtracking(target - nums[i], i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(begin(candidates), end(candidates));
        nums = candidates;
        n = nums.size();
        backtracking(target, 0);
        return ans;
    }
};