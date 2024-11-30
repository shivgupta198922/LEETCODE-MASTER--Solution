class Solution {
public:
    int tribonacci(int n) {
        int fib[100];
        fib[0]=0;
        fib[1]=1;
        fib[2]=1;
        if(n==0)
        return 0;
        if(n==1)
        return 1;
        if(n==2)
        return 1;
        for(int i=3; i<=n; i++){
            fib[i]=fib[0]+fib[1]+fib[2];
            fib[0]=fib[1];
            fib[1]=fib[2];
            fib[2]=fib[i];
        }
        return fib[n];
    }
};