class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n=s.size(), ones=count(s.begin(), s.end(), '1'), zeros=n-ones;
        string ans=string(ones-1, '1')+string(zeros, '0')+string(1,'1');
        return ans;
    }
};