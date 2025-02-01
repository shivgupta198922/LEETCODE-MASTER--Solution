class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        if(nums.size()==1)
        {
            return true;;
        }
        int count=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]%2 != nums[i+1]%2)
            {
                count++;
              
            }
            else{
                return false;
            }
            
        }
        return true;
    }
};