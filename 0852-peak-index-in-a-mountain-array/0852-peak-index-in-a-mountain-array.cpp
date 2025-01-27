class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        vector<int> ans(arr.begin(), arr.end());
        sort(ans.begin(), ans.end());
        for(int  i=0; i<arr.size(); i++){
            if(arr[i]==ans[ans.size()-1]){
                return i;
               
            }
        }
        
        return -1;
    }
};