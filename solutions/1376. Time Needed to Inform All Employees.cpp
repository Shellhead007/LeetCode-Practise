class Solution {
public:
    vector<vector<int> >adj;
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        adj.resize(n);
        for(int i=0;i<n;i++) {
            if(manager[i]!=-1) {
                adj[manager[i]].push_back(i);
            }
        }
        return dfs(headID, informTime);
    }
private:
    int dfs(int node,vector<int>& informTime) {
        int time = 0;
        for(int i = 0; i < adj[node].size();i++) {
            int local_time = dfs(adj[node][i],informTime);
            time = max(time,local_time);
        }
        return informTime[node] + time;
    }
};
