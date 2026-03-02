// BFS (Breadth First Search Traversal)
#include<bits/stdc++.h>
using namespace std;

void print_level(vector<int> &onboard)
{
    for(int &x : onboard)
        cout<<x<<" ";
    cout<<endl;
}


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

    // Visited Array
    vector<bool> visited(n+1,false); 
    // Queue for Processing
    queue<int> q;
    // Breadth First Search Traversal (BFS)
    for(int i=1;i<=n;i++)
    {
        if(visited[i])
            continue;
        q.push(i);
        visited[i] = true;
        while(!q.empty())
        {
            int level_sz = q.size();
            vector<int> onboard;
            for(int j=0;j<level_sz;j++)
            {
                int x = q.front();
                q.pop();
                onboard.push_back(x);
                // Push Neighbours
                for(int k=0;k<adj_list[x].size();k++)
                {
                    int neigh = adj_list[x][k];
                    if(!visited[neigh])
                    {
                        visited[neigh] = true;
                        q.push(neigh);
                    }
                }
            }
            print_level(onboard);
        }
    }
    return 0;
}
