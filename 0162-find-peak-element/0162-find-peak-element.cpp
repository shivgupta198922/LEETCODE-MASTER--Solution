class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        vector<int>ans(nums.begin(), nums.end());

        sort(ans.begin(),ans.end());
        for(int i=0; i<nums.size(); i++){
            if(ans[ans.size()-1]==nums[i])
            return i;
        }

        //return nums[];
        return -1;
        
    }
};