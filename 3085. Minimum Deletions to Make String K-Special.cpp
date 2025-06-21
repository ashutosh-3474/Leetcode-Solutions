class Solution {
public:
    int minimumDeletions(string word, int k) {
        map <char , int> mp;
        for (auto it : word ) mp[it]++;
        int res = word.size();
        for (auto it: mp)
        {
            int del=0;
            for (auto b : mp)
            {
                if (b.second < it.second) del += b.second;
                else del += max(b.second - it.second -k, 0);
            }
            res = min(res, del);
        }
        return res;
    }
};