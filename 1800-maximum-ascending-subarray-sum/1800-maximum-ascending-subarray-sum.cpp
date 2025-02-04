class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxi=0,prefix=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1])
            {
                prefix+=nums[i];
            }
            else{
                maxi=max(maxi,prefix);
                prefix=nums[i];
            }
        }

        return max(maxi,prefix);
        
    }
};