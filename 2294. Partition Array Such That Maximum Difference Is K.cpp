class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 1, j = 0;
        sort(nums.begin(), nums.end());
        for (int i=1;i<n;i++)
        {
            if (nums[i] - nums[j] <= k) continue;
            else 
            {
                j=i;
                cnt++;
            }
        }
        return cnt;
    }
};