class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
       // sort(piles.begin(), piles.end());
        int s=0, end=0,ans,mid;
        long long sum;
        for(int i=0; i<piles.size(); i++){
            sum+=piles[i];
            end=max(end, piles[i]);
        }
        s=sum/h;
        if(!s){
            s=1;
        }
        while(s<=end){
            mid=s+(end-s)/2;
            int total_time=0;
            for(int i=0; i<piles.size(); i++){
                total_time+=piles[i]/mid;
                if(piles[i]%mid){
                    total_time++;
                }
            }
            if(total_time>h){
                s=mid+1;
            }
            else{
                ans=mid;
                end=mid-1;
            }
        }
        return ans;
    }
};