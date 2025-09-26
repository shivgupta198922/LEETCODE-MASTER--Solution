class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=1;
         if(nums.empty())return 0;
        int n=nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]!=nums[k-1]){
                nums[k]=nums[i];
                k++;
            }
        }
        return k;
    }
};