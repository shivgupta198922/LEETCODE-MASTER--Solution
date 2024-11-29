class Solution {
public:

void backtrack(vector<int>&candidates,int target,int curr,vector<vector<int>>&ans,vector<int>&temp){
    if(curr==candidates.size()){
        if(target==0){
            ans.push_back(temp);
        }
        return;
    }
    //if possible
    if(candidates[curr]<=target){
        temp.push_back(candidates[curr]);
        backtrack(candidates,target-candidates[curr],curr,ans,temp);
        temp.pop_back();
    }
    //backtrack 
    backtrack(candidates,target,curr+1,ans,temp);
}

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        backtrack(candidates,target,0,ans,temp);
        return ans;

    }
};