class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 2; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;  // Skip duplicates

            int start = i + 1, end = nums.size() - 1;
            while(start < end) {
                int sum = nums[i] + nums[start] + nums[end];
                if(sum == 0) {
                    ans.push_back({nums[i], nums[start], nums[end]});
                    while(start < end && nums[start] == nums[start + 1]) start++;  // Skip duplicates
                    while(start < end && nums[end] == nums[end - 1]) end--;  // Skip duplicates
                    start++;
                    end--;
                } else if(sum < 0) {
                    start++;
                } else {
                    end--;
                }
            }
        }
        return ans;
    }
};
