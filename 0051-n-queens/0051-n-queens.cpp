class Solution {
public:
    map<int,int> straightline;
    map<int,int> diagonallyleft;
    map<int,int> diagonallyright;
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> output;
        vector<int> path;
        solve(n,0,output,path);
        return output;        
    }

    void solve(int& n,int row,vector<vector<string>>& output,vector<int> path){
        if(row==n){
            make_ans(output,path,n);
            return;
        }
        for(int i=0;i<n;i++){
            if(isSafe(row,i,n)){
                path.push_back(i);
                straightline[i]++;
                diagonallyright[row+i]++;
                diagonallyleft[row-i]++;
                solve(n,row+1,output,path);
                straightline[i]--;
                diagonallyright[row+i]--;
                diagonallyleft[row-i]--;
                path.pop_back();
            }
        }
        return;
    }

    bool isSafe(int row,int col,int n){
        if (straightline[col] || diagonallyright[row + col] || diagonallyleft[row-col]) {
            return false;
        }
        return true;
    }

    void make_ans(vector<vector<string>>& output,vector<int> path,int n){
        vector<string> ans;
        for(auto i:path){
            string temp(n,'.');
            temp[i]='Q';
            ans.push_back(temp);
        }
        output.push_back(ans);

    }
};