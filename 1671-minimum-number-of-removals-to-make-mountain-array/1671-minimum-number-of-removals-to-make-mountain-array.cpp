class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        // Combination of Longest Increasing Subsequence and Trapping Rain Water
        vector<int> leftDP(nums.size(), 1), rightDP(nums.size(), 1);
        // Find LIS from left
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    leftDP[i] = max(leftDP[i], leftDP[j] + 1);
                }
            }
        }
        // Find LIS from right
        for (int i = nums.size() - 1; i >= 0; --i) {
            for (int j = nums.size() - 1; j > i; --j) {
                if (nums[i] > nums[j]) {
                    rightDP[i] = max(rightDP[i], rightDP[j] + 1);
                }
            }
        }
        // Find largest mountain by finding largest sum
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            // Make sure there is a left and right slope, or else it's not a mountain
            if (leftDP[i] != 1 && rightDP[i] != 1) {
                ans = max(ans, leftDP[i] + rightDP[i]);
            }
        }
        /* Debugging purposes
        for (int i = 0; i < leftDP.size(); ++i) cout << leftDP[i] << endl;
        cout << "RIGHT" << endl;
        for (int j = 0; j < rightDP.size(); ++j) cout << rightDP[j] << endl;
        */
        // Return the number of numbers to remove to form the mountain
        return nums.size() - ans + 1;
    }
};
