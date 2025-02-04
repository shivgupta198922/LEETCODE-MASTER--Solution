class Solution {
public:
    int trap(vector<int>& height) {
        int lmax=0, rmax=0, water=0,n=height.size(), hmax=height[0], index=0;
         // maximum building 
        for(int i=1; i<n; i++){
           if(hmax<height[i]){
            hmax=height[i];
            index=i;
           } 
        }
        // left max building
        for(int i=0; i<index; i++){
            if(lmax>height[i]){
                water+=lmax-height[i];
            }
            else{
                lmax=height[i];
            }
        }
        for(int i=n-1; i>index; i--)
        {
            if(rmax>height[i]){
                water+=rmax-height[i];
            }
            else{
                    rmax=height[i];
            }
            
        }
        return water;
    }
};