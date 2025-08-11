class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int small=INT_MIN;
        int longest=1;
        int ct=0;
        for(int i=0; i< n; i++){
            if(nums[i]-1==small){
                ct+=1;
                small=nums[i];
            }
            else if(nums[i]!=small){
                ct=1;
                small=nums[i];
            }
            longest=max(longest, ct);

        }

        return longest;
    }
    
};