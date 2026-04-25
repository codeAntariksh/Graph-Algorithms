#include<bits/stdc++.h>
using namespace std;

int timer = 1;

void dfs_traversal(int i, int parent, vector<vector<int>>& adj_list, vector<bool>& visited, vector<int>& time, vector<int>& mini, vector<pair<int,int>>& ans) {
    visited[i] = true;
    time[i] = mini[i] = timer++;

    for (int node : adj_list[i]) {
        if (node == parent) continue; 

        if (!visited[node]) {
            dfs_traversal(node, i, adj_list, visited, time, mini, ans);
            
            mini[i] = min(mini[i], mini[node]);

            // Check if edge is bridge
            if (mini[node] > time[i]) {
                ans.push_back({i, node});
            }
        } 
        else {
            // Back-edge found: update mini with discovery time of the visited node
            mini[i] = min(mini[i], time[node]);
        }
    }
}
int main()
{
    int m; // No of Edges
    int n; // No of Vertexes
    cin>>m>>n;
    vector<vector<int>> adj_list(n);
    for(int i=0;i<m;i++)
    {
        int p,q;
        cin>>p>>q;
        adj_list[p].push_back(q);
        adj_list[q].push_back(p);
    }
    vector<bool> visited(n,false);
    vector<int> time(n);
    vector<int> mini(n,INT_MAX);
    vector<pair<int,int>> ans;
    for(int i=0;i<n;i++)
        if(!visited[i])
            dfs_traversal(i,-1,adj_list,visited,time,mini,ans);
    cout<<"The Bridges are-"<<endl;
    for(auto &it:ans)
    {
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;
}

