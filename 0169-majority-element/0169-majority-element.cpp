class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ct=0;
        int check;
        for(int i=0; i<nums.size(); i++){
            if(ct==0){
                ct=1;
                check=nums[i];
            }
            else if(nums[i]==check) ct++;
            else ct--;
        }
        int ct1=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==check) ct1++;
        }
        if(ct1>nums.size()/2) {return check;}
        else return -1;
        
    }
};