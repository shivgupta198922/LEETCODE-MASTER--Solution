class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = x ^ y;
        int count = 0;
        while(ans){
            count += (ans & 1);
            ans >>= 1;
        }
        return count;
    }
};