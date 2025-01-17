class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int start=0, end=n-1, mid,f=-1, l=-1;
        while(start<=end){
            mid=start+(end-start)/2;
            if(nums[mid]==target){
                f=mid;
                end=mid-1;
            }
            else if(nums[mid]<target){
                start=mid+1;
            }
            else end=mid-1;
        }
        start=0, end=nums.size()-1;

        while(start<=end){
            mid=start+(end-start)/2;
            if(nums[mid]==target){
                l=mid;
                start=mid+1;
            }
            else if(nums[mid]<target){
                start=mid+1;
            }
            else end=mid-1;
        }
         vector<int> a(2);
         a[0]=f;
         a[1]=l;
         return a;
    }
};