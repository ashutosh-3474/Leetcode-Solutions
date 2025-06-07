class Solution {
public:
    string clearStars(string s) {
        vector<stack<int>> st(26);
        for (int i=0;i<s.size();i++)
        {
            if (s[i]!='*') st[s[i]-'a'].push(i);
            else 
            {
                for (int j=0;j<26;j++)
                {
                    if (!st[j].empty())
                    {
                        s[st[j].top()] = '*';
                        st[j].pop();
                        break;
                    }
                }
            }
        }
        string ans;
        for (auto it: s) if (it != '*') ans.push_back(it);
        return ans;

    }
};