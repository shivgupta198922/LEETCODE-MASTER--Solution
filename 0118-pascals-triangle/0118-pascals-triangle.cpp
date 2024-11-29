class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        vector<int> prev;
        for(int i=0;i<numRows;i++)
        {
            vector<int> current(i+1,1);
            for(int j=1;j<i;j++){
                current[j] = prev[j-1]+prev[j];
            }
            result.push_back(current);
            prev=current;
        }
        return result;
    }
};