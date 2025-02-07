#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int, int> b2c, c2b;
        vector<int> req;
        for (auto it: queries)
        {
            int ball=it[0];
            int color=it[1];
            if (b2c.find(ball)!=b2c.end())
            {
                int precolor=b2c[ball];
                // cout<<precolor<<endl;
                b2c[ball]=color;
                c2b[precolor]--;
                if (c2b[precolor]==0)c2b.erase(precolor);
            }
            c2b[color]++;
            b2c[ball]=color;
            req.push_back(c2b.size());
        }
        return req;
    }
};