class Solution {
public:
    int count(vector<int> nums, int m)
    {
        int i=0, cnt = 0;
        while(i < nums.size()-1)
        {
            if (nums[i+1] -nums[i] <= m)
            {
                cnt++;
                i++;
            }
            i++;
        }
        return cnt;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int  l=0, r=nums[n-1]-nums[0];

        while(l< r)
        {
            int m= (l+r) /2;
            if (count(nums, m) >= p)
            {
                r=m;
            }
            else l=m-1;
        }
        return r;
    }
};