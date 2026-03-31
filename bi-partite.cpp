// Bi-Partite Graph Detection using BFS (Breadth First Search Traversal)
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Take Inputs of the Graph
    int n,m;
    cin>>n>>m;
    // Adjacency List
    vector<vector<int>> adj_list(n+1);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    // BFS Traversals
    // int color = 1; 1 and 0 are the colors
    // Visited Array
    vector<int> visited(n+1,-1); 
    // Queue for Processing
    queue<int> q;
    // Breadth First Search Traversal (BFS)
    for(int i = 1; i <= n; i++)
    {
        if(visited[i] != -1) continue;

        queue<int> q;
        q.push(i);
        visited[i] = 0;

        while(!q.empty())
        {
            int x = q.front();
            q.pop();

            for(int neigh : adj_list[x])
            {
                if(visited[neigh] == -1)
                {
                    visited[neigh] = 1 - visited[x];
                    q.push(neigh);
                }
                else if(visited[neigh] == visited[x])
                {
                    cout << "Not Bipartite\n";
                    return 0;
                }
            }
        }
    }
    cout << "Bipartite\n"; 
    return 0;
}
