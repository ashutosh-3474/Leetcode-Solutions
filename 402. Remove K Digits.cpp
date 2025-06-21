class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n = num.size();
        if (n <= k) return "0"; 
        for (auto it : num)
        {
            while(!st.empty() && st.top()-'0' > it-'0' && k>0)
            {
                st.pop();
                k--;
            }
            st.push(it);
        }
        while(k>0)
        {
            st.pop();
            k--;
        }
        string s = "";
        while(!st.empty())
        {
            s += st.top(); 
            st.pop();
        }
        // reverse(s.begin(), s.end());
        while(s.size() !=0 && s[s.size()-1] == '0') s.pop_back();
        reverse(s.begin(), s.end());
        if (s=="") return "0";
        return s;
    }
};