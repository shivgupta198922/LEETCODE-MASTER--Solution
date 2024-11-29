class Solution {
public:
void subs(vector<int>& nums, vector<vector<int>>& res, vector<int>& sub, int idx) {
        // 2 2 2 3
        int l=nums.size();
        res.push_back(sub);
        for(int i=idx;i<l;i++){
            if(i!=idx && nums[i]==nums[i-1]){
                continue;
            }
            sub.push_back(nums[i]);
            subs(nums, res, sub,i+1);
            sub.pop_back();
        }
        return;
        
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> sub;
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        subs(nums, res, sub, 0);
        return res;
    }
};