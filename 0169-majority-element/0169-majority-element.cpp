#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sort the array
        return nums[nums.size() / 2]; // Return the middle element
    }
};
