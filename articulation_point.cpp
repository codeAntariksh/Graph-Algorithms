#include <bits/stdc++.h>
using namespace std;

int timer = 1;

void dfs_traversal(int i, int parent, vector<vector<int>>& adj_list, vector<bool>& visited, vector<int>& time, vector<int>& mini, vector<bool>& is_articulation) 
{
    visited[i] = true;
    time[i] = mini[i] = timer++;
    int child_count = 0;

    for (int node : adj_list[i]) 
    {
        if (node == parent) continue;

        if (!visited[node]) {
            child_count++;
            dfs_traversal(node, i, adj_list, visited, time, mini, is_articulation);
            
            
            mini[i] = min(mini[i], mini[node]);

            // Articulation Point Check
            if ((parent != -1) && (mini[node] >= time[i])) {
                is_articulation[i] = true;
            }
        } 
        else 
        {
            mini[i] = min(mini[i], time[node]);
        }
    }

    // If Root Node, then Articulation Point Check
    if (parent == -1 && child_count > 1) 
    {
        is_articulation[i] = true;
    }
}

int main() {
    int n, m; 
    if(!(cin >> n >> m)) return 0;

    vector<vector<int>> adj_list(n);
    for (int i = 0; i < m; i++) {
        int p, q;
        cin >> p >> q;
        adj_list[p].push_back(q);
        adj_list[q].push_back(p);
    }

    vector<bool> visited(n, false);
    vector<int> time(n, 0);
    vector<int> mini(n, 0);
    vector<bool> is_articulation(n, false); 

    for (int i = 0; i < n; i++) 
    {
        if (!visited[i]) 
        {
            dfs_traversal(i, -1, adj_list, visited, time, mini, is_articulation);
        }
    }

    cout << "The Articulation Points are:" << endl;
    for (int i = 0; i < n; i++) 
    {
        if(is_articulation[i]) 
        {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}
