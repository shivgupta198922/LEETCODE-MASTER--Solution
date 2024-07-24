class Solution {
public:
    using int3=array<int, 3>;
    static int convert(int x, vector<int>& mapping){
        if (x==0) return mapping[0];//  edge case
        int z=0;
        for(int pow10=1; x>0; pow10*=10){
            auto [q, r]=div(x, 10);
            z+=mapping[r]*pow10;
            x=q;
        }
        return z;
    }

    static vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        const int n=nums.size();
        vector<int3> mapNum(n);
        for(int i=0; i<n; i++){
            int x=nums[i];
            mapNum[i]={convert(x, mapping),i,  x};//(mapping nums, idx, x)
        }
        sort(mapNum.begin(), mapNum.end());// Use default sort is better
        for(int i=0; i<n; i++)
            nums[i]=mapNum[i][2];
        return nums;
    }
};


auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();