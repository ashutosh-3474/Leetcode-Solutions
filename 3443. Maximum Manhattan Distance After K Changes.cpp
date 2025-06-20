class Solution {
public:
    int maxDistance(string s, int p) {
        map<char, int> mp;
        int k=p;
        int mx=0;
        for (auto it: s)
        {
            k=p;
            mp[it]++;
            int dist=0;
            if (mp['N']<mp['S'])
            {
                dist+=mp['S'];
                if (k>=mp['N'])
                {
                    dist+=mp['N'];
                    k-=mp['N'];
                }
                else
                {
                    dist-=(mp['N']-k);
                    dist+=k;
                    k=0;
                }
            }
            else {
                dist+=mp['N'];
                if (k>=mp['S'])
                {
                    dist+=mp['S'];
                    k-=mp['S'];
                }
                else
                {
                    dist-=(mp['S']-k);
                    dist+=k;
                    k=0;
                }
            }
            // cout<<dist;
            if (mp['E']<mp['W'])
            {
                dist+=mp['W'];
                if (k>=mp['E'])
                {
                    dist+=mp['E'];
                    k-=mp['E'];
                }
                else
                {
                    dist-=(mp['E']-k);
                    dist+=k;
                    k=0;
                }
            }
            else {
                dist+=mp['E'];
                if (k>=mp['W'])
                {
                    dist+=mp['W'];
                    k-=mp['W'];
                }
                else
                {
                    dist-=(mp['W']-k);
                    dist+=k;
                    k=0;
                }
            }
            // cout<<dist<<endl;
            mx=max(dist, mx);
        }
        return mx;
    }
};