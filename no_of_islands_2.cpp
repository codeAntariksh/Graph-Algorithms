#include<bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> rnk;
int Find(int x)
{
    if(parent[x]!=x)
    {
        return parent[x]=Find(parent[x]);
    }
    return parent[x];
}
void unionByRank(int x,int y)
{
    int px = Find(x);
    int py = Find(y);
    if(rnk[px]==rnk[py])
    {
        rnk[px]++;
        parent[py] = px;
    }
    else if(rnk[px]>rnk[py])
        parent[py] = px;
    else 
        parent[px] = py;
}


bool isValid(int adjr,int adjc,int m,int n)
{
    return (adjr>=0 && adjr<m && adjc>=0 && adjc<n);
}

int main()
{
    int m;
    int n;
    cin>>n>>m;
    for(int i=0;i<n*m;i++)
    {
        parent[i] = i;
        rnk[i] = 0;
    }
    vector<vector<int>> grid(n,vector<int> (m,0);
    vector<pair<int,int>> queries;
    int query;
    cin>>query;
    for(int i=0;i<query;i++)
    {
        int x,y;
        cin>>x>>y;
        queries[i].push_back({x,y});
    }
    vector<int> ans;
    vector<vector<bool>> visited(n,vector<bool> (m,false);
    int cnt = 0;
    for(auto it:queries)
    {
        int x = it.first;
        int y = it.second;
        if(visited[x][y]==true) {
            ans.push_back(cnt);
            continue;
        }
        visited[x][y] = true;
        cnt++;
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};
        for(int i=0;i<4;i++)
        {
            int adjr = x + dx[i];
            int adjc = y + dy[i];
            if(isValid(adjr,adjc,n,m))
            {
                if(visited[adjr][adjc]==true)
                {
                    int Nodeno = x*m+y;
                    int adjNodeno = adjr*m+adjc;
                    if(find(Nodeno)!=find(adjNodeno))
                    {
                        cnt--;
                        unionByRank(Nodeno,adjNodeno);
                    }
                }
            }
        }
        ans.push_back(cnt);
    }
    cout<<"The Corresponding Islands Will be= ";
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    return 0;
}


