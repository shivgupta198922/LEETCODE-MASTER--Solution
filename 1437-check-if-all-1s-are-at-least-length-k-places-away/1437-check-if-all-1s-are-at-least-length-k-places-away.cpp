class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        // edge case
        if (!k) return true;
        // parsing nums
        for (int i = 0, j = 0, len = nums.size(); i < len; i++) {
            // element == 1 && not enough distance from the previous
            if (nums[i] && j > 0) return false;
            // otherwise we either reset or decrease j
            else j = nums[i] ? k : j - 1;
        }
        return true;
    }
};