class Solution {
public:
    bool isPerfectSquare(int num) {
        int s=0,e=num,mid;
        if(num<2){
            return 1;
        }
        while(s<=e){
            mid=s+(e-s)/2;
            if(mid==num/mid){
                return 1;
            }
            else if(mid<num/mid){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return 0;
    }
};