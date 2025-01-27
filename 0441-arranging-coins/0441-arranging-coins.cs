public class Solution {
    public int ArrangeCoins(int n) {
        int i=1;
        int c=0;
        while(i<=n){
            n=n-i;
            i++;
            c++;
        }
         return c;
    }
   
}