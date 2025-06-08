class Solution {
public:
    vector<int> asteroidCollision(vector<int>& as) {
        stack <int> st;
        for (auto it : as)
        {
            if(st.empty() || st.top() * it >=0 || it>=0 )
            {
                st.push(it);
            }
            else 
            {
                bool ck = 1;
                while(!st.empty() && st.top() * it < 0)
                {
                    if (abs(st.top()) < abs(it)) 
                    {
                        st.pop();
                    }
                    else if (abs(st.top()) == abs(it))
                    {
                        ck=0;
                        st.pop();
                        break;
                    }
                    else {ck=0; break;}
                }
                if (ck ) st.push(it);
            }
        }
        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};