class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int , int>mp;
        int n= nums2.size();
        mp[nums2[n-1]]=-1;
        stack<int> st;
        st.push(nums2[n-1]);
        for (int i=n-2;i>=0;i--)
        {
            while(!st.empty() && st.top()<=nums2[i]) st.pop();
            mp[nums2[i]] = st.empty()?  -1:st.top();
            st.push(nums2[i]);
        }

        vector<int> ans(nums1.size());
        for (int i=0;i<nums1.size();i++)
        {
            ans[i]= mp[nums1[i]];
        }
        return ans;
        
    }
};