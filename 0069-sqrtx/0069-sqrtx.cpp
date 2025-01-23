class Solution {
public:
    int mySqrt(int x) {
       int  start=0,end=x,mid,ans;
       if(x<2)
       {
        return x;
       }
        while(start<=end){
            mid=start+(end-start)/2;
            if(mid==x/mid){
               return mid;
            }
            else if(mid<x/mid){
                ans=mid;
                start=mid+1;
            }
            else {
                end=mid-1;
            }


        }
        return ans;
        
    }
};