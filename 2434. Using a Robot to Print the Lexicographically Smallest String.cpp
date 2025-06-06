class Solution {
public:
    string robotWithString(string s) {
        int n=s.size();
        string p="";
        stack<char> st;
        vector<char>mn(n);
        mn[n-1] = s[n-1];
        for (int i=n-2;i>=0;i--) mn[i] = min(mn[i+1], s[i]);
        int i = 0;
        while(i<n)
        {
            if (st.empty() || st.top() > mn[i])
            {
                st.push(s[i]);
                i++;
            }
            else 
            {
                p+=st.top();
                st.pop();
            }
        }
        while(!st.empty()) 
        {
            p+=st.top();
            st.pop();
        }
        return p;
        
    }
};