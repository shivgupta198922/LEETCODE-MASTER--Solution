class Solution {
public:
    int addDigits(int num) {
         while(num>9){ //to check num is greater than 9 its mean single digiti number 
            int ans=0, rem;
            while(num!=0){ // to conver digit into two digit 
                rem=num%10;
                num/=10;
                ans+=rem;
            }
            num=ans;
        }
        return num;

    }
    
};