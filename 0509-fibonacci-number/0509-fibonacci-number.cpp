class Solution {
public:
    int fib(int n) {
        int fib{},fib0{0},fib1{1};
        if(n==0)
        return 0;
        if(n==1)
        return 1;
        for(int i=2;i<=n;i++)
        {
            fib=fib0+fib1;
            fib0=fib1;
            fib1=fib;
        }
        return fib;
    }
};
