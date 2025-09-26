class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int k = 0;
        int n = nums.size();

        for (int i = 0; i < n; ) {
            // check if there are at least 2 elements left and first two are same
            if (i + 1 < n && nums[i] == nums[i + 1]) {
                // if third element exists and is same, keep only two
                nums[k] = nums[i];
                nums[k + 1] = nums[i + 1];
                k += 2;
                i += 2;
                // skip any extra duplicates beyond two
                while (i < n && nums[i] == nums[i - 1]) i++;
            }
            else { // single element
                nums[k++] = nums[i++];
            }
        }

        return k;
    }
};
