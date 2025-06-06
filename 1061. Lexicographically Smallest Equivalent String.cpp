#include<bits/stdc++.h>

class Solution {
public:
    int dfs(vector<vector<int>>adj, int node, int mn, vector<int>& vis)
    {
        vis[node]=1;
        mn = min(mn, node);
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                mn = min(mn, dfs(adj, it, mn, vis));
            }
        }
        return mn;
    }
    string smallestEquivalentString(string s1, string s2, string str) {
        int n= s1.size();
        vector<vector<int>> adj(26);
        for (int i=0;i<n;i++)
        {
            int a=s1[i]-'a', b=s2[i]-'a';
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int m = str.size();
        for(int i=0;i<m;i++)
        {
            vector<int> vis(26);
            int a = str[i]-'a';
            int b = dfs(adj, a, a, vis);
            str[i]=b+'a';
        }
        return str;

    }
};