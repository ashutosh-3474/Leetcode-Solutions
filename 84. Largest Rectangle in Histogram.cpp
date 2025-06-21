class Solution {
public:
    vector<int> nse(vector<int>& arr)
    {
        int n= arr.size();
        vector<int> ans(n, n);
        stack<int> st;
        st.push(n-1);
        for (int i=n-2;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if (st.empty()) ans[i] = n;
            else ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> pse(vector<int>& arr)
    {
        int n= arr.size();
        vector<int> ans(n, -1);
        stack<int> st;
        st.push(0);
        for (int i=1;i<n;i++)
        {
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if (st.empty()) ans[i] = -1;
            else ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> ns, ps;
        ps = pse(heights);
        ns = nse(heights);
        int mx = 0;
        int n= heights.size();
        for (int i=0;i<n;i++)
        {
            cout<<ns[i]<<ps[i]<<endl;
            int area = heights[i] * (ns[i] - ps[i] - 1);
            mx = max(mx , area);
        }
        return mx;
    }
};