#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // Taking Input
    int n;
    cin>>n;
    vector<string> list(n);
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        list[i] = s;
    }
    string startword;
    cin>>startword;
    string targetword;
    cin>>targetword;
    // Essentials
    unordered_set<string> st;
    for(int i=0;i<n;i++)
    {
        st.insert(list[i]);
    }
    // Writing the BFS Algorithm
    queue<pair<string,int>> q;
    q.push({startword,1});
    int ans = -1;
    st.erase(startword);
    while(!q.empty())
    {
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();
        if(word==targetword)
        {
            ans = steps;
            break;
        }
        for(int i=0;i<word.size();i++)
        {   
            char original = word[i];
            for(char c = 'a';c<='z';c++)
            {
                if(c==original) continue;
                word[i] = c;
                if(st.find(word)!=st.end())
                {
                    st.erase(word);
                    q.push({word,steps+1});
                }
            }
            word[i] = original;
        }
    }
    cout<<ans;
    return 0;
}
