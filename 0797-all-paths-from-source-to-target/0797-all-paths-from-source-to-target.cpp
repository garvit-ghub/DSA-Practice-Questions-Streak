class Solution {
public:
    void dfs(int node,vector<vector<int>>&graph,vector<int>&path,
    vector<vector<int>>&ans){
        int n=graph.size();
        if(node==n-1){
            ans.push_back(path);
            return;
        }
        for(auto it:graph[node]){
            path.push_back(it);
            dfs(it,graph,path,ans);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>path;
        vector<vector<int>>ans;
        path.push_back(0);
        dfs(0,graph,path,ans);
        return ans;
    }
};