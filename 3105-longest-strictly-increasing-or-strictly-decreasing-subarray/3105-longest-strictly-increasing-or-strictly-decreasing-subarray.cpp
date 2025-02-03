class Solution {
public:
    int longestMonotonicSubarray(std::vector<int>& nums) {
        if (nums.size() == 1)
            return 1;
        
        int maxLength = 1;
        int currentLength = 1;
        std::string direction;
        
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                if (direction != "increasing") {
                    direction = "increasing";
                    currentLength = 1;
                }
                ++currentLength;
                maxLength = std::max(maxLength, currentLength);
            } else if (nums[i] < nums[i - 1]) {
                if (direction != "decreasing") {
                    direction = "decreasing";
                    currentLength = 1;
                }
                ++currentLength;
                maxLength = std::max(maxLength, currentLength);
            } else {
                currentLength = 1;
            }
        }
        
        return maxLength;
    }
};