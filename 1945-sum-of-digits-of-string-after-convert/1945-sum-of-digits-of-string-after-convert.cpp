class Solution {
public:
    int getLucky(string s, int k) {
        int ans = convert(s);
        for(int i=1; i<k; i++)
        {
            ans=sumofdigit(ans);
            
        }
        return ans;    
    }
    int convert(string s)
    {
        int sum=0;
        for(char c :s)
        {
            int value = c-'a'+1;
            sum += value < 10 ? value :(value %10 + value/10);  
        }
        return sum;
    }
    int sumofdigit(int num)
    {
        int sum=0;
        while(num>0)
        {
        sum+=num%10;
        num=num/10;
        }
        return sum;

    }

};