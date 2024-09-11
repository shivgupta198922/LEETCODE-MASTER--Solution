class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorresult=start^goal;
        int ans=0;
        while(xorresult>0){
            ans += xorresult & 1;
            xorresult>>=1;
        }
        return ans;
    }
};