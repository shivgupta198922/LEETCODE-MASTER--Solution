class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> directions = {{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}};
        
        int row=grid.size();

        int col= grid[0].size();
        if(row==0 || col==0) return -1;
        if(grid[0][0]!=0 | grid[row-1][col-1]!=0) return -1;

        grid[0][0] = 1;
        queue<pair<int, int>> q;
        q.push(make_pair(0,0));
        while(!q.empty()){
            auto curr= q.front();
            int x= curr.first;
            int y= curr.second;
            if(x==row-1 && y==col-1) return grid[x][y];

            for(auto direction : directions){
                int new_x= x+ direction[0];
                int new_y= y+ direction[1];
                if(new_x >=0 && new_x<row && new_y>=0 && new_y<col && grid[new_x][new_y]==0){
                    q.push(make_pair(new_x, new_y));
                    grid[new_x][new_y]= grid[x][y]+1;
                }

            }
            q.pop();

        }
        return -1;

    }
};