public class Solution {
    public bool Search(int[] nums, int target) {

       // int n=nums.length();
        for(int i=0; i<nums.Length; i++){
            if(nums[i]==target){
                return true;
            }
        }
        return false;
    }
}