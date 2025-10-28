class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        for(int i=n-2; i>=0; i--){
            for(int j=0; j<=i;j++){
                if(nums[j]>nums[j+1]){
                    swap(nums[j], nums[j+1]);
                }
            }
        }
        
    }
};