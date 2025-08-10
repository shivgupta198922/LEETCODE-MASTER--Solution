class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         int n=matrix.size();
        int m=matrix[0].size();
        int low=0,high=(n*m)-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int x=mid/m;
            int y=mid%m;

            if(matrix[x][y]==target)
             return true;

            else if(matrix[x][y]>target) 
              high=mid-1;
            else 
              low=mid+1;
        }
        return false;
    }
};