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
int main()
{
    int n; // No of Accounts
    vector<vector<string>> accounts(n);
    for(int i=0;i<n;i++)
    {
        int m;
        cin>>m;
        for(int j=0;j<m;j++){
            string temp;
            cin>>temp;
            accounts[i].push_back(temp);
        }
    }
    for(int i=0;i<n;i++)
        {
            parent.push_back(i);
            rnk.push_back(0);
        }
        unordered_map<string,int> mpp;
        for(int i=0;i<n;i++)
        {
            for(int j = 1; j < accounts[i].size(); j++)
            {
                if(mpp.find(accounts[i][j]) != mpp.end())
                {
                    unionByRank(i, mpp[accounts[i][j]]);
                }
                else
                {
                    mpp[accounts[i][j]] = i;
                }
            }
        }
        unordered_map<int, vector<string>> groups;
        for (auto &it : mpp) {
            string email = it.first;
            int node = it.second;
            int parentNode = Find(node);
            groups[parentNode].push_back(email);
        }
        vector<vector<string>> ans;
        for (auto &it : groups) {
            int node = it.first;
            vector<string> emails = it.second;

            sort(emails.begin(), emails.end());

            vector<string> temp;
            temp.push_back(accounts[node][0]); // name
            temp.insert(temp.end(), emails.begin(), emails.end());

            ans.push_back(temp);
        }
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i][0]<<": ";
            for(int j=1;j<ans[i].size();j++)
                cout<<ans[i][j]<<" ";
            cout<<endl;
        }
    return 0;
}
