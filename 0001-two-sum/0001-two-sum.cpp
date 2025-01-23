class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i,j,a,b;
        for( i=0; i<nums.size()-1; i++){
            for ( j=i+1; j<nums.size(); j++){
                if(nums[i] + nums[j]==target){
                    a=i;
                    b=j;
                    break;
                }
            }
        }
        vector<int> ans(2);
        ans[0]=a;
        ans[1]=b;
        return ans;
    }
};