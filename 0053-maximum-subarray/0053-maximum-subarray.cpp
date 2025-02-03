class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int maxi=INT_MIN,p=0;
       for(int i=0; i<nums.size(); i++){
        p+=nums[i];
        maxi=max(maxi, p);
        if(p<0){
            p=0;
        }
       }
       return maxi;
    }
};