class Solution {
public:
    bool isConnectedToParent(vector<vector<int>>& adj,int c,int x)
    {
        for(auto y:adj[x]){if(y==c)return 1;}
        return 0;
    }
    void display_adj_list(vector<vector<int>>& adj)
    {
        int nn=adj.size();
        for(int i=0;i<nn;i++)
        {
            cout<<i<<"->";
            for(auto x:adj[i])
            cout<<x<<" ";
            cout<<endl;
        }
    }
void form_adj_list(vector<vector<int>>& grid,vector<vector<int>>& adj,vector<vector<int>>& node)
    {
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int x=grid[i][j],nod=node[i][j];
                if(x==1)
                {
                    if(j>0)
                    adj[nod].push_back(node[i][j-1]);
                    if(j<m-1)
                    adj[nod].push_back(node[i][j+1]);
                }
                else if(x==2)
                {
                    if(i>0)
                    adj[nod].push_back(node[i-1][j]);
                    if(i<n-1)
                    adj[nod].push_back(node[i+1][j]);
                }
                else if(x==3)
                { 
                    if(j>0)
                    adj[nod].push_back(node[i][j-1]);
                    if(i<n-1)
                    adj[nod].push_back(node[i+1][j]);
                }
                else if(x==4)
                {
                    if(j<m-1)
                    adj[nod].push_back(node[i][j+1]);
                    if(i<n-1)
                    adj[nod].push_back(node[i+1][j]);
                }
                else if(x==5)
                {
                    if(j>0)
                    adj[nod].push_back(node[i][j-1]);
                    if(i>0)
                    adj[nod].push_back(node[i-1][j]);
                }
                else
                {
                    if(j<m-1)
                    adj[nod].push_back(node[i][j+1]);
                    if(i>0)
                    adj[nod].push_back(node[i-1][j]);
                }
            }
        }
    }

    bool canReachDestination(vector<vector<int>>& adj)
    {
        int nn=adj.size();
        queue<int> q;
        vector<int> vis(nn,0);
        q.push(0);
        vis[0]=1;
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();

            for(auto x:adj[curr])
            {
                if(!vis[x] && isConnectedToParent(adj,curr,x))
                {
                    vis[curr]=1;
                    q.push(x);
                    if(x==nn-1)
                    return 1;
                }
            }
        }
        return 0;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),nn=n*m,k=0;
        if(nn==1)return 1;
        vector<vector<int>> node(n,vector<int> (m)),adj(nn);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                node[i][j]=k;
                k++;
            }
        }
        //making adjejency list
        form_adj_list(grid,adj,node);
        //display adj list
        //display_adj_list(adj);
        //is valid path to reach destination using BFS
        return canReachDestination(adj);
    }
};