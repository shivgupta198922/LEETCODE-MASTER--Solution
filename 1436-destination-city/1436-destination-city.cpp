#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    string dfs(string v, unordered_map<string, string>& edge){
        if (edge.count(v)==0) return v;
        return dfs(edge[v], edge);
    }
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string> edge;
        for(auto& e:paths){
           edge[e[0]]=e[1];
        }
        return move(dfs(paths[0][0], edge));
    }
};